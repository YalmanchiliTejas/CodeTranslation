#include<iostream>
#include<cstdio>
#define MAXN 1000
using namespace std;
int main(){
	int h,w;
	cin>>h>>w;
	char a[MAXN][MAXN]={'\0'};
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=h;i++){
		int flag=0;
			for(int j=1;j<=w;j++){
				if(a[i][j]=='.'){
					flag++;
				}else{
					break;
				}
			}
			if(flag==w){
				for(int j=1;j<=w;j++){
					a[i][j]='x';
				}
			}
	}
	// cout<<endl;
	// for(int i=1;i<=h;i++){
	// 	int flag=0;
	// 	for(int j=1;j<=w;j++){
	// 			cout<<a[i][j];
	//
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	for(int i=1;i<=w;i++){
		int flag=0;
		for(int j=1;j<=h;j++){
			if(a[j][i]=='.'||a[j][i]=='x'){
				flag++;
			}else{
				break;
			}
		}
		if(flag==h){
			// cout<<"yes"<<i<<endl;
			for(int j=1;j<=h;j++){
				a[j][i]='x';
			}
		}
	}
	// cout<<endl;
	// for(int i=1;i<=h;i++){
	// 	int flag=0;
	// 	for(int j=1;j<=w;j++){
	// 			cout<<a[i][j];
	//
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	for(int i=1;i<=h;i++){
		int flag=0;
		for(int j=1;j<=w;j++){
			if(a[i][j]!='x'){
				cout<<a[i][j];
				flag=1;
			}
		}
		if(flag)
		cout<<endl;
	}
	return 0;
}
