#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
/*--Input//////////////////////////////////////////////////*/
inline void IN(void){return;}
template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
    cin >> first;
    IN(rest...);
    return;
}
#define SS(T, ...)      T __VA_ARGS__; IN(__VA_ARGS__);
/*--Output/////////////////////////////////////////////////*/
inline int p(void){cout << endl; return 0;}
template<class Head> int p(Head&& head){cout << head;p();return 0;} template<class Head,class... Tail> int p(Head&& head,Tail&&... tail){cout<<head<<" ";p(forward<Tail>(tail)...);return 0;}
struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
        if(AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;


#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second < b.second; }

const int MOD = 1000000007;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    SS(int,h,w)
    vector<vector<char>> a(h, vector<char>(w));
    vector<bool> d_h(h), d_w(w);
    rep(i, h){
        rep(j, w){
            cin >> a.at(i).at(j);
            if(a.at(i).at(j) == '#'){
                d_h.at(i) = true;
                d_w.at(j) = true;
            }
        }
    }

    rep(i, h){
        if(!d_h.at(i)) continue;
        rep(j, w){
            if(!d_w.at(j)) continue;
            cout << a.at(i).at(j);
        }
        p();
    }
}