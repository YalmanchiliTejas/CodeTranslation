#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h,w; cin>>h>>w;
	vector<vector<string>> a(h+1,vector<string>(w+1,"."));
	rep(i,h){
		string s; cin>>s;
		rep(j,w){
			a[i][j]=s[j];
		}
	}
	int cnt=0;
	rep(i,h){
		rep(j,w){
			if(a[i][j]=="#") cnt++;
		}
	}
	int ans=1;
	int j=0;
	rep(i,h){
		if(a[i+1][j]=="#") {ans++;}
		else if(a[i][j+1]=="#") {ans++; i--; j++;}
	}
	cout<<(cnt==ans?"Possible":"Impossible")<<endl;
}