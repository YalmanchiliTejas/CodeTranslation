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

int main() {
SS(ll,n,k,m);
vl ord(m, -1); // かつて来た地点を求める
    vl rireki, syu;
    ll res = 0;
    rep(j,n){
        // かつて来た地点に戻ったら
        if (ord[k] != -1) {
            int p = ord[k];
            for (ll i = p; i < j; ++i) syu.push_back(rireki[i]);
            break;
        }
        ord[k] = j;
        rireki.push_back(k);
        res += k;
        k = (k * k) % m;
    }
    n -= rireki.size();

    // 戻る前に N 項目に到達した場合
    if (n == 0) {
        p(res);
        return 0;
    }
    // 周期の累積和をとる
    vl sum(syu.size() + 1, 0);
    rep(i,syu.size()) sum[i+1] = sum[i] + syu[i];
    // 周期を q 週して r あまる
    ll q = n / syu.size();
    ll r = n % syu.size();
    res += sum[syu.size()] * q + sum[r];
    p(res);
}
