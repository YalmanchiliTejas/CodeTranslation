#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>v[2];
ll f(ll a[],ll n,ll i,ll j,ll turn){
    if(i==n || j==-1 || i>j){
        return 0;
    }
    if(v[turn][i][j]!=0){
        return v[turn][i][j];
    }
    if(turn==0){
        ll x=0,y=0;
        y=f(a,n,i+1,j,1)+a[i];
        x=f(a,n,i,j-1,1)+a[j];
        v[turn][i][j]= max(x,y);
    }
    else{
        ll x=0,y=0;
        y=f(a,n,i+1,j,0)-a[i];
        x=f(a,n,i,j-1,0)-a[j];
        v[turn][i][j]=min(x,y);
    }
    return v[turn][i][j];
}
int main() {
	ll n,i,j,k;
	cin>>n;
	ll a[n];
	vector<ll>tmp(n+1,0);
	for(i=0;i<n;i++){
	    cin>>a[i];
	    v[0].push_back(tmp);
	    v[1].push_back(tmp);
	}
	cout<<f(a,n,0,n-1,0);
	return 0;
}