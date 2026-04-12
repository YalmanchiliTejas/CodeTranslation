#include<iostream>
#include<iostream>
using namespace std;
int main(){
   int t,n,sam;
   string comand;

   while(cin >> n,n != 0){
	sam = 1;
	int dice[6] = {1,2,3,5,4,6};
	for(int i=0;i<n;i++){
		cin >> comand;
		if(comand == "North"){
			t = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[3];
			dice[3] = t;
		}else if(comand == "East"){
			t = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[2];
			dice[2] = t;
		}else if(comand == "West"){
			t = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[4];
			dice[4] = t;
		}else if(comand == "South"){
			t = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[1];
			dice[1] = t;
		}else if(comand == "Right"){
			t = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[4];
			dice[4] = t;
		}else if(comand == "Left"){
			t = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[3];
			dice[3] = dice[2];
			dice[2] = t;
		}

		sam += dice[0];
	}

	cout << sam << endl;

   }

   return 0;
}