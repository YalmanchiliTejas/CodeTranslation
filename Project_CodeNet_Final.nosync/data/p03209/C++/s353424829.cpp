/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,x;
ll pat[55],tot[55];

ll dfs(ll lev,ll eat){//burger level and level to eat
	if(lev==0 && eat==1)return 1;
	if(lev==0 && eat==0)return 0;
	ll res=0;
	eat--;//B
	if(eat==0)return res;
	if(eat>=tot[lev-1]){
		res+=pat[lev-1];
		eat-=tot[lev-1];
	}else{
		res+=dfs(lev-1,eat);
		return res;
	}//level n-1
	if(eat>=1){
		eat--;
		res++;
	}
	if(eat==0){
		return res;
	}//P
	if(eat>=tot[lev-1]){
		res+=pat[lev-1];
		eat-=tot[lev-1];
	}else{
		res+=dfs(lev-1,eat);
		return res;
	}//level n-1
	eat--;//B
	if(eat>0)cout<<"WHATTHEF**K"<<endl;
	return res;
}

int main(){

	cin>>n>>x;
	pat[0]=1;
	tot[0]=1;
	for(int i=1;i<=50;i++){
		pat[i]=pat[i-1]*2+1;
		tot[i]=tot[i-1]*2+3;
	}
	cout<<dfs(n,x);

	return 0;
}
