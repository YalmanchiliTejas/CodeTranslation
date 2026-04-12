#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
	int H, W;
	char a[120][120] = {}, temp[120][120] = {};
	
	cin>>H>>W;
	
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			cin>>a[i][j];
		}
	}
	
	while(1){
		int flag = 0;
		for(int i = 1; i <= H; i++){
			int f = 0, x=0;
			for(int j = 1; j <= W; j++){
				if(a[i][j] == '#'){
					f = 1;
					//flag = 1;
					//break;
				}
				if(a[i][j] == 'X')x++;
				
			}
			if(f == 0){
				if(x == W){//cout<<"aaaaa"<<endl;
					a[i][0] = 'A';
				}else{
				flag = 1;
				for(int j = 1; j <= W; j++)a[i][j] = 'X';
				}
			}
			
			
		}
		
		for(int i = 1; i <= W; i++){
			int f = 0, x = 0;
			for(int j = 1; j <= H; j++){
				if(a[j][i] == '#'){
					f = 1;
					//flag = 1;
					//break;
				}
				if(a[j][i] == 'X')x++;
			}
			if(f == 0){
				if(x == H){
				}else{
					flag=1;
				
					for(int j = 1; j <= H; j++)a[j][i] = 'X';
				}
			}
			
			
			
		}
		flag  = 0;
			for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++){
			if(temp[i][j] != a[i][j]) flag = 1;
			temp[i][j] = a[i][j];
		}
		/*
			for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			//if(a[i][j] != 'X')cout<<a[i][j];
			cout<<a[i][j];
		}cout<<endl;
		}cout<<endl;
		*/
		
		
		if(flag == 0)break;
		//cin>>flag;
	}
	
	for(int i = 1; i <= H; i++){
		if(a[i][0] == 'A')continue;
		for(int j = 1; j <= W; j++){
			if(a[i][j] != 'X')cout<<a[i][j];
		}
		cout<<endl;
	}
	
	
	return 0;
}