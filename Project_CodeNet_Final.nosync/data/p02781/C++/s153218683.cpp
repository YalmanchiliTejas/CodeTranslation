#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<P> VP;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF = 1e18+18;
const ll MAX = 100005;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a, b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n, m, arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n, arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define dbgmint(n, arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;
#define out(a) cout<<a<<endl
#define out2(a, b) cout<<a<<" "<<b<<endl
#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second

template<class T>
bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if(b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

template<typename T>
istream &operator>>(istream &i, vector<T> &v) {
    rep(j, v.size())i>>v[j];
    return i;
}

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len = v.size();
    for(int i = 0; i < len; ++i) {
        s<<v[i];
        if(i < len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len = vv.size();
    for(int i = 0; i < len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

ll dp[101][2][5];

void debug(ll i, ll j, ll l) {
    rep(x, i) {
        rep(y, j) {
            rep(z, l) {
                if(x == 0)continue;
                cerr<<x<<" "<<y<<" "<<z<<endl;
                dbg(dp[x][y][z]);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);
    memset(dp,0, sizeof(dp));
    string s;
    ll K;
    cin>>s>>K;
    ll n = s.length();

    dp[0][0][0] = 1;

    //上位i桁まで見て j自由に選べるか w数字を書き込んだか kいくつ0にしたか
    rep(i, n) {
        rep(j, 2) {
            rep(k, K+1) {
                //自由に選べる
                if(j == 1) {
                    //0書き込む場合
                    dp[i+1][1][k] += dp[i][1][k];
                    //0以外を書き込む場合
                    dp[i+1][1][k+1] += dp[i][1][k]*9;


                } else {
                    //制約あり
                    ll x = s[i]-'0';
                    //i+1桁目をxと比べる
                    // x-1以下については以降自由に選べる
                    // xを書き込んだ場合は自由にえらべない
                    if(x == 0){
                        dp[i+1][0][k] += dp[i][0][k];
                    }else{
                        //0を書き込む場合
                        dp[i+1][1][k] += dp[i][0][k];
                        //xを書き込んで、制約を維持する
                        dp[i+1][0][k+1] += dp[i][0][k];
                        //それいがい
                        dp[i+1][1][k+1] += dp[i][0][k]*(x-1);
                    };
                }
            }
        }
    }
    ll ans = 0;
    //debug(4, 2, 3);

    rep(i, 2) {
        ans += dp[n][i][K];
    }

    cout<<ans<<endl;
    return 0;
}

