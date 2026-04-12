#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

#define si(a)           scanf("%d",&a)
#define sii(a,b)        scanf("%d %d",&a,&b)
#define siii(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define sl(a)           scanf("%lld",&a)
#define sll(a,b)        scanf("%lld %lld",&a,&b)
#define slll(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)

#define un(x)           x.erase(unique(all(x)), x.end())
#define xx              first
#define yy              second
#define pb              push_back
#define mp              make_pair
#define all(v)          v.begin(),v.end()
#define D(x)            cerr << #x " = " << x << '\n'
#define DBG             cerr << "Hi!" << '\n'

#define CLR(a)          memset(a,0,sizeof(a))
#define SET(a)          memset(a,-1,sizeof(a))

#define PI              acos(-1.0)

//inline int setBit(int n,int pos) { return n = n | (1 << pos); }
//inline int resetBit(int n,int pos) { return n = n & ~(1 << pos); }
//inline bool checkBit(int n,int pos) { return (bool)(n & (1 << pos)); }
//inline int countBit(ll n) { return __builtin_popcountll(n); }


//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction

/******************************************************************************************/

const int MAX = 3010;
const int INF = 0x3f3f3f3f;
//const double inf = 1.0/0.0;
//const int MOD = 1000000007;

int ara[MAX];
ll dp[MAX][MAX];

ll call(int L,int R) {
    if(L>R) return 0;
    if(dp[L][R]!=-1) return dp[L][R];
    ll ret = max(ara[L]-call(L+1,R),ara[R]-call(L,R-1));
    return dp[L][R] = ret;
}


int main() {
//    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    si(n);
    for(int i=1;i<=n;i++) si(ara[i]);

    SET(dp);
    cout << call(1,n) << endl;

    return 0;
}

