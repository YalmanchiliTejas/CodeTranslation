#include <bits/stdc++.h>
using namespace std;
// #define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define chmin(a,b) (a)=min((a),(b));
#define chmax(a,b) (a)=max((a),(b));
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(v) cerr<<(#v)<<":";for(auto(x):(v)){cerr<<" "<<(x);}cerr<<endl;
#define printVS(vs) cerr<<(#vs)<<":"<<endl;for(auto(s):(vs)){cerr<<(s)<< endl;}
#define printVV(vv) cerr<<(#vv)<<":"<<endl;for(auto(v):(vv)){for(auto(x):(v)){cerr<<" "<<(x);}cerr<<endl;}
#define printP(p) cerr<<(#p)<<(p).first<<" "<<(p).second<<endl;
#define printVP(vp) cerr<<(#vp)<<":"<<endl;for(auto(p):(vp)){cerr<<(p).first<<" "<<(p).second<<endl;}

inline void output(){ cerr << endl; }
template<typename First, typename... Rest>
inline void output(const First& first, const Rest&... rest) {
    cerr << first << " "; output(rest...);
}

using ll = long long;
using Pii = pair<int, int>;
using TUPLE = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
// const int inf = 1ll << 60;
const int inf = 1e9;
const int mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int n;
int h[16], w[16];
int c[4][4];
int dp[1 << 16];

bool valid(int i, int j, int k, int state){
    vi cnt(3);
    rep2(ii, max(0, i - h[k] + 1), min(i + 1, 4)) {
        rep2(jj, max(0, j - w[k] + 1), min(j + 1, 4)) {
            if ((state >> (4*ii+jj)) & 1) cnt[c[ii][jj]]++;
        }
    }
    int cnt_positive = (int)(cnt[0] > 0) + (int)(cnt[1] > 0) + (int)(cnt[2] > 0);
    return cnt_positive == 1;
}

int stamp(int i, int j, int k, int state) {
    rep2(ii, max(0, i - h[k] + 1), min(i + 1, 4)) {
        rep2(jj, max(0, j - w[k] + 1), min(j + 1, 4)) {
            state = (state & ((1 << 16) - 1 - (1 << (4*ii+jj))));
        }
    }
    return state;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    rep(i, n) cin >> h[i] >> w[i];
    rep(i, 4) rep(j, 4) {
        char x;
        cin >> x;
        if (x == 'R') c[i][j] = 0;
        if (x == 'G') c[i][j] = 1;
        if (x == 'B') c[i][j] = 2;
    }

    fill(dp, dp + (1 << 16), inf);
    queue<int> que;
    int s = (1 << 16) - 1;
    que.emplace(s);
    dp[s] = 0;
    while (!que.empty()) {
        int state = que.front(); que.pop();
        rep(k, n) {
            rep(i, 7) {
                rep(j, 7) {
                    if (valid(i, j, k, state)) {
                        int nstate = stamp(i, j, k, state);
                        if (nstate == 0) {
                            cout << dp[state] + 1 << endl;
                            return 0;
                        }
                        if (dp[nstate] == inf) {
                            dp[nstate] = dp[state] + 1;
                            que.push(nstate);
                        }
                    }
                }
            }
        }
    }

}