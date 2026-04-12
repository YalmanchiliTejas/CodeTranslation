#include <bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define rep(i,l,r) for(int i=l;i<r;i++)
#define bep(i,l,r) for(int i=l;i>=r;i--)
#define ld long double
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define el '\n'
#define sz(s) s.size()
#define all(v) v.begin(),v.end()
#define mii map<int,int>
#define mr  make_pair
using namespace std;

int inf = 1e18;
const int N = 5e5+5;

int mod = 1e9+7;
//int powmod(int a,int b) {int res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}


signed main()
{
    io
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        if(n==m)
            cout<<"Yes"<<el;
        else
            cout<<"No"<<el;
    }


        return 0;
    }
