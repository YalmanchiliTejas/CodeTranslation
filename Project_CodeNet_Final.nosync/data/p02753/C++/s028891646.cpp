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
#define SV(type,c,n) vector<type> c(n);for(auto& i:c)cin >> i;
/*--Output/////////////////////////////////////////////////*/
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
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
    SS(string,s)
    set<char>S;
    rep(i,3)S.insert(s[i]);
    Yes(S.size()==2);
}