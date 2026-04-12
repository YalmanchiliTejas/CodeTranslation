
#include<bits/stdc++.h>


using namespace std;

using ll   = long long;
using ii   = pair   < int , int >;
using i3   = pair   < int , ii  >;
using li   = pair   < ll  , int >;
using lii  = pair   < ll  , ii  >;
using pll  = pair   < ll  , ll  >;
using vi   = vector < int       >;
using vl   = vector < ll        >;
using vii  = vector < ii        >;
using vli  = vector < li        >;
using vpll = vector < pll       >;
using vi3  = vector < i3        >;
using vlii = vector < lii       >;


const int N = 2e5 + 5;
const ll INF = 1e17 + 7;
const double eps = 1e-9 , PI = acos(-1);


int n , m;

ll a[N];
ll odd [N];
ll even[N];
ll mem[N][4];
int vis[N][4];
int color = 0;

ll dp(int i , int f){
    if(i > n){
            if(n&1){
                    if(f) return 0;
                    else return -INF;
            }
            else {
                    return 0;
            }
    }

    ll &ret = mem[i][f];
    if(vis[i][f] == color) return ret;
    vis[i][f] = color;

    ret = a[i] + dp(i + 2 , f);
    if(n&1){
            if(f < 2){
                    ret = max(ret , dp(i + 1 , f + 1));
            }
    }
    else {
            if(f < 1){
                    ret = max(ret , dp(i + 1 , f + 1));
            }
    }

    return ret;
}

void solve(int testCase){

    scanf("%d" , &n);

    for(int i = 1 ; i <= n ; i ++){
            scanf("%lld" , &a[i]);
    }

    color = 1;
    ll ans = dp(1 , 0);
    color = 2;
    ans = max(ans , dp(1 , 0));

    printf("%lld\n" , ans);
}

main(){

    int t = 1;
    // scanf("%d" , &t);

    for(int testCase = 1 ; testCase <= t ; testCase ++){
            solve(testCase);
    }

    return 0;
}
