//@formatter:off
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define rrep(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = int(s); i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<P>
#define vvp vector<vector<P>>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
void YES(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

int dp[2010][2010];
int mx[2010];
int allMax = -inf;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi a(n * 3);
    cin >> a;
    rep(i, n * 3) a[i]--;
    rep(i, 2010) rep(j, 2010) dp[i][j] = -inf;
    rep(i, 2010) mx[i] = -inf;
    int AD = 0;
    auto update = [&](int i, int j, int val) {
        chmax(dp[i][j], val);
        chmax(mx[i], val);
        chmax(dp[j][i], val);
        chmax(mx[j], val);
        chmax(allMax, val);
    };
    auto addAll = [&]() {
        AD++;
    };
    update(a[0], a[1], 0);
    rep2(i, 1, n) {
        vi v;
        vector<tuple<int, int, int>> ch;
        rep2(j, i * 3 - 1, i * 3 + 2) {
            v.pb(a[j]);
        }
        rep(j, 3) rep(k, 3) {
                vi rem;
                rep(l, 3) {
                    if (l != j and l != k) rem.pb(v[l]);
                }
                if (j == k) {
                    rep(l, n) {
                        int now = mx[l];
                        if (rem[0] == rem[1]) {
                            chmax(now, dp[l][rem[0]] + 1);
                        }
                        ch.eb(v[j], l, now);
                    }
                } else {
                    int now = dp[rem[0]][rem[0]] + 1;
                    chmax(now, allMax);
                    ch.eb(v[j], v[k], now);
                }
            }
        int dis = 0;
        if (v[0] == v[1] and v[1] == v[2]) {
            addAll();
            dis = 1;
        }
        for (auto[j, k, val] : ch) update(j, k, val-dis);
//        rep(j, n) rep(k, n) {
//                printf("%d %d %d %d\n", i, j, k, dp[j][k]+AD);
//            }
    }
    int last = a[n * 3 - 1];
    update(last, last, dp[last][last] + 1);
    cout << allMax+AD << endl;
}