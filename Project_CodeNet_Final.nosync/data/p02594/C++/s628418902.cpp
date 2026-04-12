/**
 *              "Bismillahir Rahmanir Rahim"
 *                 _                       _            __
 *   _ __ ___   __| |_   _  __ _ _ __ ___ (_)_ __      / /
 *  | '_ ` _ \ / _` | | | |/ _` | '_ ` _ \| | '_ \    / /
 *  | | | | | | (_| | |_| | (_| | | | | | | | | | |  / /
 *  |_| |_| |_|\__,_|\__, |\__,_|_| |_| |_|_|_| |_| /_/
 *                   |___/
 *                 _                       _        ___   ___ _____
 *   _ __ ___   __| |_   _  __ _ _ __ ___ (_)_ __  / _ \ / _ \___  |
 *  | '_ ` _ \ / _` | | | |/ _` | '_ ` _ \| | '_ \| | | | | | | / /
 *  | | | | | | (_| | |_| | (_| | | | | | | | | | | |_| | |_| |/ /
 *  |_| |_| |_|\__,_|\__, |\__,_|_| |_| |_|_|_| |_|\___/ \___//_/
 *                   |___/
 *   
 *   email:      mdyamin007@yahoo.com
 *   website:    mdyamin007.github.io
 *   facebook:   fb.com/mdyamin007
 *   linkedIn:   linkedin.com/in/mdyamin
 *   created:    06.06.2020
 * 
**/

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define sf1(a) sf("%lld", &a)
#define sf2(a,b) sf("%lld %lld", &a, &b)
#define sf3(a,b,c) sf("%lld %lld %lld", &a, &b, &c)
#define sf4(a,b,c,d) sf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define sf5(a,b,c,d,e) sf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define RESET(a, b) memset(a, (b), sizeof(a))
#define lb lower_bound
#define ub upper_bound
#define newline pf("\n")
#define endl '\n'
#define sfd(n) sf("%lf", &n)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SZ(v) (int)v.size()
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define sqr(a) ((a)*(a))
#define REVERSE(v) reverse(ALL(v))
#define on(n,i) (n|=(1LL<<i))
#define isOn(n,i) (n&(1LL<<i))
#define off(n,i) (n = isOn(n,i) ? n ^ (1LL<<i) : n)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b)*b)
#define watch(a) cout << (#a) << " is " << (a) << '\n'
#define watch2(a,b) cout << (#a) << " is " << (a) << " and " << (#b) << " is " << (b) << '\n'
#define MIN3(a,b,c) MIN(a, MIN(b,c))
#define MAX3(a,b,c) MAX(a, MAX(b,c))
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

template <class T>  inline void chmax(T &x,T &y) {if(x < y) swap(x,y);}
template <class T>  inline void chmin(T &x,T &y) {if(x > y) swap(x,y);}

const int INF = 0x3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 10e-10;

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/




void Solution() {
    int n;
    sf1(n);
    if(n >= 30) pf("Yes\n");
    else pf("No\n");
}


int32_t main() {
    //FAST_IO
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif

    int tc = 1;
	//sf1(tc);
    //cin >> tc;

    FOR(tn,1,tc+1,1) {
        //pf("Case %lld:", tn);
        //cout << "Case " << tn << ":";
        Solution();  
	}

    return 0;
}
