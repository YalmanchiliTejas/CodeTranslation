#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<functional>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.20f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define cotu cout
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,x,m; cin >> n >> x >> m;
    vector<ll> v;
    map<ll,ll> mp;

    ll cnt = 0;
    while(mp.count(x) == 0){
        v.pb(x);
        mp[x] = cnt;
        cnt++;
        x = (x*x) % m;
    }
    ll start = mp[x];
    ll T = cnt - start;

    if(n <= start){
        ll ans = 0;
        rep(i,0,n) ans += v[i];
        cout << ans << enld;
        return 0;
    }

    ll sumT = 0;
    rep(i,0,T) sumT += v[start+i];

    ll ans = 0;
    rep(i,0,start) ans += v[i];
    n -= start;

    ans += n/T * sumT;

    n %= T;

    rep(i,0,n) ans += v[start+i];

    cout << ans << enld;
    return 0;
}