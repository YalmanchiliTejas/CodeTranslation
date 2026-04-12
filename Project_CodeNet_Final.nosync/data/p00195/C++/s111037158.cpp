#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int sale[5][3];
	while(1){
		scanf("%d %d",&sale[0][0],&sale[0][1]);
		if(sale[0][0]==0 && sale[0][1]==0) break;
		for(int i=1;i<5;i++){
			cin>>sale[i][0]>>sale[i][1];
		}
		for(int i=0;i<5;i++){
			sale[i][2] = sale[i][0]+sale[i][1];
		}

		int max = sale[0][2];
		int maxi = 0;
		for(int i=1;i<5;i++){
			if(max <sale[i][2]){
				max = sale[i][2];
				maxi = i;
			}
		}

		printf("%c %d\n",'A'+maxi,max);

	}

	return 0;
}