#include<bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 32);
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;
typedef pair<ll, ll> P;
template <class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

#define Endl endl

/*--------------------template--------------------*/

ll d[10][100];

int main() {
    cin >> n >> m;
    vp v(m);
    vi va(n);
    REP(i,n) {
        va[i] = i + 1;
    }
    REP(i,m) {
        cin >> v[i].first >> v[i].second;
        d[v[i].first][v[i].second] = 1;
        d[v[i].second][v[i].first] = 1;
    }
    do{
        if(va[0]!=1){
            cout << ans << Endl;
            return 0;
        }
        REP(i,n-1) {
            if(d[va[i]][va[i+1]]){
                if(i==n-2)
                    ans++;
                continue;
            }else{
                break;
            }
        }
    } while (next_permutation(ALL(va)));
}