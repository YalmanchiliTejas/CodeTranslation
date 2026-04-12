#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==v.size()-1?']':','); return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

using T = tuple<int,int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    map<T,ll> dp;
    dp[{0,0,0}] = 0;
    rep(i,n) {
        // k = 0
        {
            int l = max(0,n/2-(n-i+1)/2);
            int r = min(i/2,n/2);
            for(int j = l; j <= r; j++) {
                if(!dp.count({i,j,0})) continue;
                if(dp.count({i+1,j,0})) chmax(dp[{i+1,j,0}],dp[{i,j,0}]);
                else dp[{i+1,j,0}] = dp[{i,j,0}];
                if(dp.count({i+1,j+1,1})) chmax(dp[{i+1,j+1,1}],dp[{i,j,0}]+a[i]);
                else dp[{i+1,j+1,1}] = dp[{i,j,0}]+a[i];
            }
        }
        // k = 1
        {
            int l = max(0,n/2-(n-i)/2);
            int r = min((i+1)/2,n/2);
            for(int j = l; j <= r; j++) {
                if(!dp.count({i,j,1})) continue;
                if(dp.count({i+1,j,0})) chmax(dp[{i+1,j,0}],dp[{i,j,1}]);
                else dp[{i+1,j,0}] = dp[{i,j,1}];
            }
        }
    }
    cout << max(dp[{n,n/2,0}],dp[{n,n/2,1}]) << endl;
}