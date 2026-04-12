#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>

//#define DEBUG 1

#define int long long
#define for0(i,n) for (int i=0; i<n; i++)
#define iter(c) for(auto it=c.begin(); it!=c.end(); it++)
#define vec(x) vector< x >
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define sqr(x) 1LL*(x)*(x)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#ifdef int
#define read(x) scanf("%lld",&x);
#else
#define read(x) scanf("%d",&x);
#endif

#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<sz(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define debug
#endif

using namespace std;

typedef long long ll;

const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

ll a[55];

ll solve(int N, ll K) 
{
    ll x_tot = 0;
    for0(i,N) {
        ll x_min = (a[i]+K+1)/(N+1);
        x_tot += x_min;
    }
    return x_tot;
}

int32_t main()
{
    #ifdef DEBUG
    freopen("C.txt","r",stdin);
    //freopen("","w",stdout);
    #endif

    int N; 
    cin >> N;
    for0(i,N) {
        cin >> a[i];
    }
    
    ll K = 0;
    while (true) {
        ll mink = solve(N,K);
        //pr(K) pr(mink) nl
        if (mink <= K) 
            break;
        else 
            K = mink;
    }
    cout<<K<<endl;
    return 0;
}
