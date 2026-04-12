#include<bits/stdc++.h>

using namespace std;

#define    fastio        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define    f             first
#define    s             second
#define    ub            upper_bound
#define    lb            lower_bound
#define    pb            push_back
#define    mset(x,val)   memset(x,val,sizeof(x))
#define    all(x)        (x).begin(),(x).end()
#define    foo(i,a,b)    for(long long i=(a);i<=(b);i++)
#define    rep(i,a,b)    for(long long i=(a);i>=(b);i--)
#define    FOR(i,v)      for(auto &(i):(v))

using  ll    =   long long;
using  ld    =   long double;
using  vl    =   vector<ll>;
using  pll   =   pair<ll, ll>;
using  vll   =   vector<pll>;
using  MAP   =   map<ll, ll>;
using  sl    =   set<ll>;
using  sll   =   set<pll>;
using  MAPs  =   map<ll, sl>;
using  MAPv  =   map<ll, vl>;


const ll inf = LLONG_MAX;
const ll mod = 1e9 + 7;
const ll N   = 2e5 + 5;//change it if u have to

int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

/*********************************************************************************************************/
/***************************************** VARIABLE DECLARATIONS *****************************************/
ll x;

/***************************************** FUNCTION IMPLEMENTATIONS **************************************/


/***************************************** START OF MAIN FUNCTION ****************************************/
void MAIN() {
    cin >> x;
    cout << (x < 30 ? "No\n" : "Yes\n");
}

int main() {
    fastio;
    int t = 1;

    // cin>>t;
    while (t -- > 0) {
        MAIN();
    }

// #ifndef ONLINE_JUDGE
//     cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
// #endif

}
