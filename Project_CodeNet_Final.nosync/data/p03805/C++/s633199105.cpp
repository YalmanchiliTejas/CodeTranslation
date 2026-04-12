#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

#define DEBUG_MODE
#ifdef DEBUG_MODE
#define dump(x) cout << #x << " : " << x << " "
#define dumpL(x) cout << #x << " : " << x << '\n'
#define LINE cout << "line : " << __LINE__ << " "
#define LINEL cout << "line : " << __LINE__ << '\n'
#define dumpV(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << " "
#define dumpVL(v) cout << #v << " : ["; for(auto& t : v) cout << t << ", "; cout<<"]" << endl
#define STOP assert(false)
#else
#define dump(x) 
#define dumpL(x) 
#define LINE 
#define LINEL 
#define dumpV(v) 
#define dumpVL(v) 
#define STOP assert(false)
#endif
#define mp make_pair
 
namespace std {
template<class S, class T>
ostream &operator <<(ostream& out, const pair<S, T>& a) {
    out << '(' << a.fi << ", " << a.se << ')';
    return out;
}
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vi(n));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        d[a][b] = d[b][a] = 1;
    }
    vector<int> id(n);
    rep(i, n) id[i] = i;

    int ans = 0;
    do {
        bool f = id[0] == 0;
        rep(i, n-1) f &= d[id[i]][id[i+1]];
        if(f) ++ans;
    }while(next_permutation(all(id)));

    cout << ans << endl;

    return 0;
}