#include<iostream>
using namespace std;
char a[101][101];
bool dn[101];
bool dn1[101];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cin>>a[i][j];
		if(a[i][j]=='#') {
			dn[i]=true;
			dn1[j]=true;
		  } 	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dn[i]&&dn1[j]){
				cout<<a[i][j];
			}
		}
		cout<<endl;
	}
}