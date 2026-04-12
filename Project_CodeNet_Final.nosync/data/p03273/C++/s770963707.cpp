#include <bits/stdc++.h>
using namespace std;
int h,w;
char a[100][100];
bool H[100];//yokoretu
bool W[100];//tateretu
int main(){
	cin>>h>>w;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>a[i][j];
	for(int i=0;i<100;i++)H[i]=false,W[i]=false;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j]=='#')goto lp;
		}
		H[i]=true;
		lp:;
	}
	for(int j=0;j<w;j++){
		for(int i=0;i<h;i++){
			if(a[i][j]=='#')goto lop;
		}
		W[j]=true;
		lop:;
	}
	for(int i=0;i<h;i++){
		if(H[i]==true)continue;
		for(int j=0;j<w;j++){
			if(W[j]==false)cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}