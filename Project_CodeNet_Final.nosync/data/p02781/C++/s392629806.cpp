#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
/*--Input//////////////////////////////////////////////////*/
inline void IN(void){return;}
template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
#define SS(T, ...)      T __VA_ARGS__; IN(__VA_ARGS__);
#define SV(type,c,n) vector<type> c(n);for(auto& i:c)cin >> i;
/*--Output/////////////////////////////////////////////////*/
inline int p(void){cout << endl; return 0;}
template<class Head> int p(Head&& head){cout << head;p();return 0;} template<class Head,class... Tail> int p(Head&& head,Tail&&... tail){cout<<head<<" ";p(forward<Tail>(tail)...);return 0;}
struct ProconInit {
    static constexpr bool AUTOFLUSH = false;
    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
        if(AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.first+a.second > b.first+b.second; }

ll dp[2][110][50];  /* dp[id][i+1][j] : 先頭からi桁目までで0でない数がj個現れるs以下の数の個数。
                                       ただし、id = 0 のとき現時点でsと等しい。
                                       id = 1 のとき現時点でsより小さいことが確定。 */
int main() {
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    
    dp[0][0][0] = 1;
    rep(id, 2) {
        rep(i, n) {
            rep(j, 4) {
                ll lim = s[i] - '0';  //  先頭からi桁目にはlim以下の数を置ける
                if(id) {
                    lim = 9;
                }
                rep(x,lim+1) {  // 先頭からi桁目にxを置くとする
                    dp[id || x < lim][i+1][j + (x != 0)] += dp[id][i][j];
                }
            }
        }
    }
    
    ll ans = 0;
    rep(id, 2) {  
        ans += dp[id][n][k];
    }
    
    p(ans);
    return 0;
}