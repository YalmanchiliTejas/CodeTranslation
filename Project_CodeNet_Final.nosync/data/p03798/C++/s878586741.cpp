#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define mm(i,v) memset(i,v,sizeof i);
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+10;
bool f=false;
int n,a[maxn];
char s[maxn];

int check(int i,int x){
	int l=i-1,r=i+1;
	if(i==1)
		l=n;
	if(i==n)
		r=1;
	if(x){
		if((s[i]=='o'&&a[r]!=a[l])||(s[i]=='x'&&a[r]==a[l]))
			return true;
		else
			return false;
	}
	else{
		if((s[i]=='o'&&a[r]==a[l])||(s[i]=='x'&&a[r]!=a[l]))
			return true;
		else
			return false;
	}
}

void dfs(int dep,int x){
	if(f)
		return ;
	a[dep]=x;
	if(dep>n)
		return ;
	if(n==dep&&check(dep,x)&&check(1,a[1])){
		f=true;
		return ;
	}
	if(x){
		if(s[dep]=='o')
			dfs(dep+1,a[dep-1]^1);
		else
			dfs(dep+1,a[dep-1]);
	}
	else{
		if(s[dep]=='o')
			dfs(dep+1,a[dep-1]);
		else
			dfs(dep+1,a[dep-1]^1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>s+1;
	a[1]=1;
	dfs(2,1);
	if(!f){
		mm(a,0);
		a[1]=1;
		dfs(2,0);
	}
	if(!f){
		mm(a,0);
		a[1]=0;
		dfs(2,0);
	}
	if(!f){
		mm(a,0);
		a[1]=0;
		dfs(2,1);
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(a[i])
				cout<<"W";
			else
				cout<<"S";
		}
	}
	else
		cout<<-1;
	cout<<"\n";
	return 0;
}
