#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<chrono>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define vint(a,n) vint a(n); rep(i, n) cin >> a[i];
#define vll(a,n) vll a(n); rep(i, n) cin >> a[i];
#define ALL(n) begin(n),end(n)
#define RALL(n) rbegin(n),rend(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
using vbool=vector<bool>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll f(ll a, ll m){
    ll t = a*a;
    return (t%m);
}

int main()
{
    ll n;
    ll x, m; cin >> n >> x >> m;

    vll val(m, -1);
    vll a;
    ll ans = 0;

    ll loop=0;
    ll intt = 0;
    ll sum = 0;
    val[x] = 0;
    for(ll i=0; i<n; i++){
        // pr(x);
        ans += x;
        if(i==n-1) break;
        a.push_back(x);
        x = f(x, m);
        
        if(val[x]!=-1){
            intt = val[x];
            loop = i+1 - val[x];
            FOR(j, val[x], i+1) sum += a[j];
            break;
        }
        val[x] = i+1;
    }

    if(loop!=0) {
        ans += sum* (((n-intt)/loop) - 1);
        ll k = (n-intt)%loop;
        FOR(i, intt, intt+k) ans += a[i];
    }
    pr(ans);


    return 0;}