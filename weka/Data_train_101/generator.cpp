#include<bits/stdc++.h>
using namespace std;

#define TRAINING 101
#define TEST 31

void header(){
    puts("@relation worker");
    puts("\n@attribute skill numeric");
    puts("@attribute gender {Male,Female}");
    puts("@attribute experience numeric");
    puts("@attribute iq numeric");
    puts("@attribute hired {Yes,No}");
    puts("\n@data");
}

void test (vector<string> &v){
    freopen("datatest.arff", "w", stdout);
    header();

    for(int i=0; i<TEST; i++){
        int skill = rand()%81 + 20,
            exp = rand()%4 + 1,
            iq = rand()%81 + 70;
        string gender = v[ rand()%2];

        cout << skill << '\t' << gender << '\t' << exp 
        	 << '\t' << iq << '\n';
    }
}

int lvl_iq(int iq){
	if (iq > 144)
		return 20;
	if (iq > 129)
		return 15;
	if (iq > 119)
		return 10;
	if (iq > 109)
		return 5;
	return 0;
}

void training (vector<string> &v){
    freopen("datatraining.arff", "w", stdout);
    header();

    for(int i=0; i< TRAINING; i++){
        int skill = rand()%81 + 20,
            exp = rand()%4 + 1,
            iq = rand()%81 + 70;
        string gender = v[ rand()%2];

        cout << skill << '\t' << gender << '\t' << exp 
        	 << '\t' << iq << '\t';

    	if (iq < 90)
    		cout << "No\n";
        else if(gender == "Male"){
            if (skill + (exp*10) + lvl_iq(iq) >= 90)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else{
            if (skill + (exp*10) + lvl_iq(iq) >= 80)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int main(){
    srand(time(NULL));

    vector<string> v;
    v.emplace_back("Male");
    v.emplace_back("Female");

    test(v);
    training(v);

    return 0;
}