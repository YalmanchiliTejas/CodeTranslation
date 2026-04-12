#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono;
#define fl(i,z,n) for(int i=z;i<=(n);i++)
#define flr(i,z,n) for(int i=z;i>=(n);i--)
using namespace std;
#define ll long long 
#define printa(a,s) fl(i,0,s-1) cout<<*(a+i)<<" "; cout<<nl;
#define printv(v) fl(i,0,v.size()-1) cout<<v[i]<<" "; cout<<nl;
#define all(v) v.begin(),v.end()
#define debnl(x) cout<<#x<<"="<<x<<nl;
#define deb(x) cout<<#x<<"="<<x<<" ";
#define mkp(x,y) make_pair(x,y)
#define ump unordered_map
#define in insert
#define sz size
#define len length
#define nl '\n'
#define pb push_back
#define in insert
#define ub upper_bound
#define lb lower_bound
#define ld long double
const int MXN=1e5;
ll mod=1e9+7;
void solve(){
    ll n;
    cin>>n;
    if(n >=30) cout<<"Yes"<<nl;
    else cout<<"No"<<nl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); ll t=1;
    //cin>>t; //comment for single test
    while(t--) solve();
}