#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
string ma[maxn];
int x[maxn],y[maxn];
int h,w;
int main(){
	cin>>h>>w;
	for(int i=0;i<h;i++){
		cin>>ma[i];
	}
	for(int i=0;i<h;i++){
		int yes=1;
		for(int j=0;j<w;j++){
			if(ma[i][j]!='.'){
				yes=0;
			}
		}
		y[i]=yes;
	}
	for(int i=0;i<w;i++){
		int yes=1;
		for(int j=0;j<h;j++){
			if(ma[j][i]!='.'){
				yes=0;
			}
		}
		x[i]=yes;
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(y[i]==1) break;
			if(x[j]==1) ;
			else cout<<ma[i][j];
		}
		if (y[i]!=1)cout<<endl;
	}
}