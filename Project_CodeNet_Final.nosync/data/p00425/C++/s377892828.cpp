#include<iostream>
#include<string>
//#include<stdio.h>

using namespace std;

int main(void){
	int n,i,ans=1,temp;
	string order;
	while(cin >> n){
	if(n == 0)break;
//	cin >> n;
	int dice[6] = {1,2,3,5,4,6};
	for(i=0;i<n;i++){
		cin >> order;
		if(order == "North"){
			temp = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[3];
			dice[3] = temp;
			ans += dice[0];
		}
		else if(order == "East"){
			temp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[2];
			dice[2] = temp;
			ans += dice[0];
		}
		else if(order == "West"){
			temp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[4];
			dice[4] = temp;
			ans += dice[0];
		}
		else if(order == "South"){
			temp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
			ans += dice[0];
		}
		else if(order == "Right"){
			temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[4];
			dice[4] = temp;
			ans += dice[0];
		}
		else if(order == "Left"){
			temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[3];
			dice[3] = dice[2];
			dice[2] = temp;
			ans += dice[0];
		}
	}
	cout << ans << endl;
	ans =1;
	}
	return 0;
}