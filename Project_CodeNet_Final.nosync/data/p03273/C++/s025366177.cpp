#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	char a[105][105];
	bool s[105][105];
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++){
			cin>>a[i][j];
			s[i][j]=1;
		}	
	for(int i=1;i<=x;i++){
		int f=1;
		for(int j=1;j<=y;j++){
			if(a[i][j]=='#'){
				f=0;
				break;
			} 
		}
		if(f){
			for(int j=1;j<=y;j++)
				s[i][j]=false;
		}
	}
	for(int j=1;j<=y;j++){
		int f=1;
		for(int i=1;i<=x;i++){
			if(a[i][j]=='#'){
				f=0;
				break;
			} 
		}
		if(f){
			for(int i=1;i<=x;i++)
				s[i][j]=false;
		}
	}
	for(int i=1;i<=x;i++){
		int f=0;
		for(int j=1;j<=y;j++){
			if(s[i][j]){
				cout<<a[i][j];
				f=1;
			} 
		}
		if(f) cout<<endl;
	}
	return 0;
}
