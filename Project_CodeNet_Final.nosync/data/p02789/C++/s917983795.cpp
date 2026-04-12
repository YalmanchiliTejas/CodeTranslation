/*
    Reference :-
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define PI pair<int,int>
#define all(vec) vec.begin(),vec.end()
ll mod=1e9+7;
ll fac[100001];
ll power(ll n,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=(ans*n)%mod;
        k/=2;
        n=(n*n)%mod;
    }
    //ans=(ans-1+mod)%mod;
    return ans;
}
bool comp(PI a,PI b){
    return b.F<a.F;
}

int main(){
    //std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(m==n)cout<<"Yes";
    else cout<<"No";

	return 0;
}
