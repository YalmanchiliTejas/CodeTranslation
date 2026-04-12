#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x;
ll dfs(ll a,ll b){
	if(b==0) return 0;
	if(a==0) return 1;
	ll m = 1ll<<a;
	if(b<2*m-1) return dfs(a-1,b-1);
	return m+dfs(a-1,b-2*m+1);
}
int main(){
	cin>>n>>x;
	cout<<dfs(n,x)<<endl;
	return 0;
}