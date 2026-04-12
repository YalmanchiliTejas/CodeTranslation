#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
const int inf=(1<<30);
#define rep(i,a,n)	for(int i=a;i<n;i++)
#define rrep(i,a,n) for(int i=(a-1);i>=n;i--)
	
	ll v[10][10];
	ll x[10];
	ll ans=0;
	ll n,m;

	void solve(ll a,ll b){
		x[a]++;
		if(b==n){
			rep(i,0,n){
				if(x[i]==1)continue;
				else {
					x[a]--;
					return;
				}
			}
			ans++;
			x[a]--;
		}
		else{
			
			rep(i,0,n){
				if(v[a][i]==1&&x[i]!=1){
					solve(i,b+1);
				}
				else continue;
			}
		x[a]--;
		}
	}
	
	
int main(){
	cin>>n>>m;
	rep(i,0,m){
		ll f,t;
		cin>>f>>t;
		f--;
		t--;
		v[f][t]++;
		v[t][f]++;
	}
	solve(0,1);
	cout<<ans<<endl;
}