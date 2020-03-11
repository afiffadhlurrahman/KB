import argparse
import timeit
from collections import deque
from state import State
from heapq import heappush, heappop, heapify
import itertools

goal_state = [0, 1, 2, 3, 4, 5, 6, 7, 8]
goal_node = State
initial_state = list()
board_len = 0
board_side = 0

nodes_expanded = 0
max_search_depth = 0
max_frontier_size = 0

moves = list()
costs = set()

def bfs(start_state):
    
    global max_frontier_size, goal_node, max_search_depth

    explored, queue = set(), deque([State(start_state, None, None, 0, 0, 0)])

    while queue:

        node = queue.popleft()

        explored.add(node.map)

        if node.state == goal_state:
            goal_node = node
            return queue

        neighbors = expand(node)

        for neighbor in neighbors:
            if neighbor.map not in explored:
                queue.append(neighbor)
                explored.add(neighbor.map)

                if neighbor.depth > max_search_depth:
                    max_search_depth += 1

        if len(queue) > max_frontier_size:
            max_frontier_size = len(queue)

def expand(node):
    
    global nodes_expanded
    nodes_expanded += 1

    neighbors = list()

    neighbors.append(State(move(node.state, 1), node, 1, node.depth + 1, node.cost + 1, 0))
    neighbors.append(State(move(node.state, 2), node, 2, node.depth + 1, node.cost + 1, 0))
    neighbors.append(State(move(node.state, 3), node, 3, node.depth + 1, node.cost + 1, 0))
    neighbors.append(State(move(node.state, 4), node, 4, node.depth + 1, node.cost + 1, 0))

    nodes = [neighbor for neighbor in neighbors if neighbor.state]

    return nodes

def move(state, position):
    
    new_state = state[:]

    index = new_state.index(0)

    if position == 1:  # Up

        if index not in range(0, board_side):

            temp = new_state[index - board_side]
            new_state[index - board_side] = new_state[index]
            new_state[index] = temp

            return new_state
        else:
            return None

    if position == 2:  # Down

        if index not in range(board_len - board_side, board_len):

            temp = new_state[index + board_side]
            new_state[index + board_side] = new_state[index]
            new_state[index] = temp

            return new_state
        else:
            return None

    if position == 3:  # Left

        if index not in range(0, board_len, board_side):

            temp = new_state[index - 1]
            new_state[index - 1] = new_state[index]
            new_state[index] = temp

            return new_state
        else:
            return None

    if position == 4:  # Right

        if index not in range(board_side - 1, board_len, board_side):

            temp = new_state[index + 1]
            new_state[index + 1] = new_state[index]
            new_state[index] = temp

            return new_state
        else:
            return None

def backtrace():
    
    current_node = goal_node
    while initial_state != current_node.state:

        if current_node.move == 1:
            movement = 'Up'
        elif current_node.move == 2:
            movement = 'Down'
        elif current_node.move == 3:
            movement = 'Left'
        else:
            movement = 'Right'

        moves.insert(0, movement)
        current_node = current_node.parent

    return moves


def export(frontier, time):
    global moves
    moves = backtrace()

    print("path_to_goal: " + str(moves))
    print("cost_of_path: " + str(len(moves)))
    print("nodes_expanded: " + str(nodes_expanded))
    print("fringe_size: " + str(len(frontier)))
    print("max_fringe_size: " + str(max_frontier_size))
    print("search_depth: " + str(goal_node.depth))
    print("max_search_depth: " + str(max_search_depth))
    print("running_time: " + format(time, '.8f'))


def read(configuration):
    global board_len, board_side
    data = configuration.split(",")
    for element in data:
        initial_state.append(int(element))
    board_len = len(initial_state)
    board_side = int(board_len ** 0.5)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('algorithm')
    parser.add_argument('board')
    args = parser.parse_args()
    read(args.board)
    function = function_map[args.algorithm]
    start = timeit.default_timer()
    frontier = function(initial_state)
    op = timeit.default_timer()

function_map = {
    'bfs': bfs
}

if __name__ == '__main__':
    main()
