#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
typedef long double lld;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ONLINE_JUDGE
template<class T> T umax(T a,T b) {return (a>b?a:b);}
template<class T> T umin(T a,T b) {return (a<b?a:b);}
template<class T,class P> T umax(T a,P b) {return (a>b?a:b);}
template<class T,class P> T umin(T a,P b) {return (a<b?a:b);}

const ll mod = 1e9+7;

int X[] = {0,1,0,-1,-1,-1,1,1};
int Y[] = {1,0,-1,0,-1,1,-1,1};

ll power(ll a,ll b) {
    ll res = 1;
    while(b) {
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

const int maxn = 10;

int main() {
#ifndef ONLINE_JUDGE
    freopen("qns.txt","r",stdin);
    freopen("ans.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);
    // logic
    ll a,b,ab,u,v;
    cin >> a >> b >> ab >> u >> v;
    ll mi = 1e18;
    for(ll i=0;i<=100000;i++) mi = umin(mi,i*2*ab + umax(0,u-i)*a + umax(0,v-i)*b);
    cout << mi << endl;
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
