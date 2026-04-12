#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int k;

vector<vector<vector<ll>>> dp;

ll f(int indextoadd, bool isequal, int numleft){
	if (numleft<0){
		return 0;
	}
	if (indextoadd==s.size()){
		if (numleft==0){
			return dp[indextoadd][isequal][numleft]=1;
		} else {
			return dp[indextoadd][isequal][numleft]=0;
		}
	}
	if (dp[indextoadd][isequal][numleft]!=-1){
		return dp[indextoadd][isequal][numleft];
	}
	ll total = 0;
	for (int i = 0; i<=9; i++){
		if (isequal&&i>(s[indextoadd]-'0')){
			break;
		}
		total+=f(indextoadd+1,(isequal&&(s[indextoadd]-'0'==i)),(i==0?numleft:numleft-1));
	}
	return dp[indextoadd][isequal][numleft]=total;
}

int main(){
	cin>>s>>k;
	dp.resize(s.size()+1,vector<vector<ll>>(2,vector<ll>(k+1,-1)));
	cout<<f(0,true,k)<<endl;
	return 0;
}