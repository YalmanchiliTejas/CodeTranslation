#include<iostream>
#include<string>
#include<cstring>

using namespace std;
int main(){
	 string a[105];
	 int n,m,x1[105],y1[105];
	 memset(x1,0,sizeof(x1));
	 memset(y1,0,sizeof(y1));
	 cin>>n>>m;
	 for(int i = 0;i < n;i++){
			 string s;
			 cin>>s;
			 a[i] = s;
 	}
	for(int i = 0;i < n;i++){
		int flag = 1;
		for(int j =0;j < m;j++){
			if(a[i][j] != '.'){
				flag = 0;
			}
		}
		if(flag){
			x1[i] = 1;
		}
	}
	for(int i = 0;i < m;i++){
		int flag = 1;
		for(int j = 0;j < n;j++){
			if(a[j][i] != '.'){
				flag = 0;
			}
		}
		if(flag){
			y1[i] = 1;
		}
	}
	for(int i = 0;i < n;i++){
		if(x1[i]) continue;
		for(int j = 0; j < m;j++){
			if(y1[j]) continue;
			cout<<a[i][j];
		}
		cout<<'\n';
	}
} 