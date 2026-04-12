#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

ll solve(ll n, ll x, ll m){
    VL r(m);
    deque<ll> dq;
    rep(i, min(n, m)){
        r[x]++;
        dq.push_back(x);
        x *= x;
        x %= m;

        // 巡回検出
        if (r[x] != 0) break;
    }

    // 残りの数
    n -= dq.size();

    if (n != 0){
        // ループサイズ
        while(dq.front() != x) dq.pop_front();
        ll loop_sz = dq.size();

        // 何回ループするかを計算し、ループする数に対して加算する
        ll nq = n / loop_sz;
        while(!dq.empty()){
            ll y = dq.front(); dq.pop_front();
            r[y] += nq;
        }

        // 残りは普通に計算する
        ll nr = n % loop_sz;
        while(nr--){
            r[x]++;
            x *= x;
            x %= m;
        }
    }

    ll ans = 0;
    rep(i,m) ans += (ll)i * r[i];
    return ans;
}

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    cout << solve(n, x, m) << endl;
    
    return 0;
}
