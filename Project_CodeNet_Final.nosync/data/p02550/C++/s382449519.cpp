#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
# define pll pair<ll,ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,x,m;
	cin>>n>>x>>m;
	ll ans = 0 ;
	if(n<=m){
		for(int i = 0 ;i <n ;i++){
			ans =  ans +x;
			x = (x*x)%m;
		}
		cout<<ans;
		return 0;
	}
	ll vis[m] = {0};
	ll store[m] = {0};
	ll iter = 1;
	while(!vis[x]){
		vis[x] = iter ;
		ans += x;
		store[x] = ans ;
		x = (x*x)%m;
		++iter;
	}
	ll turns = iter - vis[x] ;
	ll cur = ans - store[x] + x ;
	n = n + 1 - iter;
	ans = ans + (n/turns)*cur;
	n = n % turns;
	for(int i = 0 ;i<n;i++){
		ans =  ans + x;
		x = (x*x)%m;
	}
	cout<<ans; 
	return 0;
}