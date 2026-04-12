#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int k;
string s;

int memo[100][2][4];

int dfs(int i,bool smaller,int c){
	if(i==s.length()) return c==k?1:0;
	if(c>k) return 0;

	if(memo[i][smaller][c]!=-1) return memo[i][smaller][c];

	int res=0;
	if(smaller){
		rep(d,10){
			res+=dfs(i+1,true,c+(d==0?0:1));
		}
	}
	else{
		rep(d,s[i]-'0'+1){
			res+=dfs(i+1,d<s[i]-'0',c+(d==0?0:1));
		}
	}
	memo[i][smaller][c]=res;
	return res;
}

int main(){
	memset(memo,-1,sizeof memo);

	cin>>s>>k;
	cout<<dfs(0,false,0)<<'\n';

	return 0;
}
