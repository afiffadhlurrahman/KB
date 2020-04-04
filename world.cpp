#include<bits/stdc++.h>

// masing masing 5 buah
int main(){
	int arr[10][10],hasil[10][10];
	memset(hasil, '\0', sizeof(hasil));
	
	srand((unsigned) time(0));
	int flag;
	
	flag = rand()%5;
	printf("flag:%d\n",flag);
	
	printf("world ke-%d\n",flag);
	//world 1
	if(flag==0){
		int arr[10][10]={{0,1,0,0,0,0,0,0,0,0},
				 		   {0,0,2,0,0,0,0,0,0,0},
				 		   {0,0,2,0,0,0,1,0,0,0},
				 		   {0,0,0,2,0,0,0,3,0,0},
				 		   {0,0,3,0,0,2,0,0,0,0},
				 		   {0,0,0,0,0,0,0,0,0,0},
				 		   {0,0,1,0,3,0,0,1,0,0},
				 		   {0,0,0,0,0,2,0,0,0,0},
				 		   {0,0,0,0,0,3,0,1,0,0},
						   {0,0,0,3,0,0,0,0,0,0}
							};							
	}
	//world 2
	else if(flag==1){
		int arr[10][10]={{0,0,0,0,0,3,0,0,1,0},
						 {0,0,2,0,2,0,3,0,0,0},
						 {0,0,0,0,0,0,0,0,1,0},
						 {0,0,0,2,0,0,3,0,0,0},
						 {0,0,0,1,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0},
						 {0,3,0,0,1,0,0,0,0,0},
						 {0,0,0,0,2,0,0,0,1,0},
						 {0,0,3,0,0,0,2,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0}
						};
	}
	//world 3
	else if(flag==2){
		int arr[10][10]={{0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,1,0,0,2,0,0,0},
						 {0,0,0,3,0,0,3,0,0,0},
						 {0,0,0,3,1,0,1,0,0,0},
						 {0,0,0,2,0,0,0,2,0,0},
						 {0,0,0,3,0,0,0,0,0,0},
						 {0,0,2,1,0,1,0,0,0,0},
						 {0,0,3,2,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0}
						};
	}
	//world 4	
	else if(flag==3){
		int arr[10][10]={{0,1,3,0,0,0,0,0,0,0},
						 {0,1,3,0,0,0,0,0,0,0},
						 {0,3,1,0,3,2,0,0,0,0},
						 {0,0,0,1,0,0,2,0,0,0},
						 {0,0,0,3,1,0,0,0,0,0},
						 {0,0,0,0,0,0,0,2,0,0},
						 {0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,2,0,2,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0}
						};
	}
	//world 5
	else if(flag==4){
		int arr[10][10]={{0,0,0,0,0,0,0,0,0,0},
						 {3,2,0,0,0,0,0,0,0,0},
						 {2,2,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,1,2,0,0,0,0},
						 {0,0,0,0,2,3,0,0,0,0},
						 {0,0,0,0,0,1,0,1,0,0},
						 {0,0,0,0,0,0,0,3,0,0},
						 {3,1,3,0,0,0,0,0,1,0}
						};
	}
	
	//count hasil
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(arr[i][j]==1){
				if(i==0){
					hasil[i+1][j]+=7;
					if(j==0){
						hasil[i][j+1]+=7;
					}
					else if(j==9){
						hasil[i][j-1]+=7;
					}
					else{
						hasil[i][j+1]+=7;
						hasil[i][j-1]+=7;						
					}
				}
				else if(i==9){
					hasil[i-1][j]+=7;
					if(j==0){
						hasil[i][j+1]+=7;	
					}
					else if(j==9){
						hasil[i][j+1]+=7;	
					}
					else{
						hasil[i][j+1]+=7;
						hasil[i][j-1]+=7;		
					}
				}
				else{
					hasil[i-1][j]+=7;
					hasil[i+1][j]+=7;
					if(j==0){
						hasil[i][j+1]+=7;
					}
					else if(j==9){
						hasil[i][j-1]+=7;
					}
					else{
						hasil[i][j+1]+=7;
						hasil[i][j-1]+=7;
					}
				}
			}
			if(arr[i][j]==2){
				if(i==0){
					hasil[i+1][j]+=11;
					if(j==0){
						hasil[i][j+1]+=11;
					}
					else if(j==9){
						hasil[i][j-1]+=11;
					}
					else{
						hasil[i][j+1]+=11;
						hasil[i][j-1]+=11;						
					}
				}
				else if(i==9){
					hasil[i-1][j]+=11;
					if(j==0){
						hasil[i][j+1]+=11;	
					}
					else if(j==9){
						hasil[i][j+1]+=11;	
					}
					else{
						hasil[i][j+1]+=11;
						hasil[i][j-1]+=11;		
					}
				}
				else{
					hasil[i-1][j]+=11;
					hasil[i+1][j]+=11;
					if(j==0){
						hasil[i][j+1]+=11;
					}
					else if(j==9){
						hasil[i][j-1]+=11;
					}
					else{
						hasil[i][j+1]+=11;
						hasil[i][j-1]+=11;
					}
				}
			}
			if(arr[i][j]==3){
				if(i==0){
					hasil[i+1][j]+=13;
					if(j==0){
						hasil[i][j+1]+=13;
					}
					else if(j==9){
						hasil[i][j-1]+=13;
					}
					else{
						hasil[i][j+1]+=13;
						hasil[i][j-1]+=13;						
					}
				}
				else if(i==9){
					hasil[i-1][j]+=13;
					if(j==0){
						hasil[i][j+1]+=13;	
					}
					else if(j==9){
						hasil[i][j+1]+=13;	
					}
					else{
						hasil[i][j+1]+=13;
						hasil[i][j-1]+=13;		
					}
				}
				else{
					hasil[i-1][j]+=13;
					hasil[i+1][j]+=13;
					if(j==0){
						hasil[i][j+1]+=13;
					}
					else if(j==9){
						hasil[i][j-1]+=13;
					}
					else{
						hasil[i][j+1]+=13;
						hasil[i][j-1]+=13;
					}
				}
			}
		}
	}
	//selesai count hasil
	
	//print world
	for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				printf("%d",arr[i][j]);
				if(j!=9)
					printf("\t");
			}
			printf("\n");
		}
	printf("\n");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d",hasil[i][j]);
			if(j!=9)
				printf("\t");
		}
		printf("\n");
	}
	return 0;
}
