#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

int main(){
	int dice[6] = {1,2,3,4,5,6};
	int total=1;
	int n;
	int tmp;
	string command;
	
	while(cin>>n,n){
		total=1;
		for(int i=0;i<6;i++)dice[i]=i+1;
		for(int i=0;i<n;i++){
			cin>>command;
			if(command == "North"){
				tmp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = tmp;
			}else if(command == "East"){
				tmp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = tmp;
			}else if(command == "South"){
				tmp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
			}else if(command == "West"){
				tmp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = tmp;
			}else if(command == "Right"){
				tmp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[3];
				dice[3] = tmp;
			}else{
				tmp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];
				dice[4] = dice[2];
				dice[2] = tmp;
			}
			total += dice[0];
		}
		cout<<total<<endl;
	}
	return 0;
}