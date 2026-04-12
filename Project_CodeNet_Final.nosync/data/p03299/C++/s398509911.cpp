#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define __builtin_popcount __builtin_popcountll

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
    os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const map<S, T> &t) {
    os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int INV_2 = (1 + MOD) / 2;

ll modpow(ll x, ll y){
    if (y < 0) return 0;
    ll r = 1, a = x % MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}
template <typename T=int>
struct Zipper{
    vector<T> dec;
    unordered_map<T, int> enc;
    Zipper(){}
    void add(T t){dec.pb(t);}
    size_t size(){return dec.size();}
    void compile(){
        sort(ALL(dec)); UNIQUE(dec);
        REP(i, dec.size()) enc[dec[i]] = i;
    }
    T operator[](int i){return dec[i];}
    int operator()(T t){return enc[t];}
    int lb(T t){return lower_bound(ALL(dec), t) - dec.begin();}
    int ub(T t){return upper_bound(ALL(dec), t) - dec.begin();}
};

int T, n, m;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    while(cin >> n){
        vi d(n);
        Zipper<int> zip;
        REP(i, n) {
            cin >> d[i];
            zip.add(d[i]);
        }
        zip.add(1);
        zip.compile();
        REP(i, n) d[i] = zip(d[i]);
        int m = zip.size();
        vector<ll> dp(1);
        dp[zip(1)] = 1;
        int prv = zip(1);
        for (int cur : d) {
            vector<ll> nxt(cur + 1);
            if (prv >= cur) {
                REP(j, prv + 1) {
                    if (cur <= j) {
                        nxt[cur] = (nxt[cur] + dp[j] * 2) % MOD;
                    } else {
                        nxt[j] = (nxt[j] + dp[j]) % MOD;
                    }
                }
            } else {
                REP(j, prv) {
                    nxt[j] = (nxt[j] + dp[j] * modpow(2, zip[cur] - zip[prv])) % MOD;
                }
                for(int j = prv; j <= cur; j ++) {
                    nxt[j] = (nxt[j] + dp[prv] * 2 * (modpow(2, zip[cur] - zip[j]) +
                            (cur == j ? 0 : MOD - modpow(2, zip[cur] - zip[j + 1]))
                                                                 )) % MOD;
                }
            }
            prv = cur;
            swap(dp, nxt);
        }
        cout << accumulate(ALL(dp), 0ll) % MOD << endl;
    }
    return 0;
}
