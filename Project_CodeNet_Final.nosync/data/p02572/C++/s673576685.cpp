
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*

WINNERS NEVER QUIT AND QUITTERS NEVER WIN!!

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef vector<long> vl;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;

#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define REV(i,a,b) for(long long i=a;i>=b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define tc ll tests;cin>>tests;while(tests--)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define coutv(v) for(auto it: (v))cout<<it<<" ";newl;
#define cout2d(v) for(auto it: (v)) {for(auto j:it) cout<<j<<" ";newl;}
#define cinv(v,n) vll (v)(n);FOR(i,0,(n)){cin>>v[i];}
#define cinvg(v,n) (v).resize(n);FOR(i,0,(n)){cin>>v[i];}
#define cin2d(v,n,m) vvll (v)(n,vll(m,0));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define cin2dg(v,n,m) (v).resize(n,vll(m));FOR(i,0,n){FOR(j,0,m){cin>>v[i][j];}}
#define newl cout<<"\n"
#define mod 1000000007
#define INF LLONG_MAX/2

long long d,x,y;//declare d,x,y outside function

void exteuc(long long A, long long B)
{
    if(B==0){
        d=A;
        x=1;
        y=0;
    }
    else{
        exteuc(B,A%B);
        long long temp=x;
        x=y;
        y=temp-(A/B)*y;
    }
}

long long modinv(long long A,long long M)
{//declare d,x,y(same as exteuc)
    exteuc(A,M);
    return (x%M+M)%M;//as x may be negative
}

int main()
{
    io;
    ll n,s=0;
    cin>>n;
    cinv(a,n)
    FOR(i,0,n)
    {
    	s+=a[i];
    }
    
    
    ll ans=((s%mod)*(s%mod))%mod;
    
    FOR(i,0,n)
    {
    	ans=(ans-(a[i]%mod*a[i]%mod)%mod+mod)%mod;
    }
    
    cout<<(ans*modinv(2,mod))%mod;
    
    return 0;
}

