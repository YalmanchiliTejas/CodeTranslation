#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

vector<pair<ll, ll>> bp(51);

// 返り値はPの数だけ
ll solve(ll n, ll x){
    if(n<=-1 || x<=0) return 0;
    ll n_size = bp[n].first+bp[n].second;
    if(x == n_size){
        // 全長の場合
        return bp[n].second;
    }
    if(x == n_size/2+1){
        // ちょっきり半分の場合
        return (bp[n].second-1)/2 + 1;
    }
    else if(x > n_size/2+1){
        // 半分を超える場合
        return (bp[n].second-1)/2 + 1 + solve(n-1, x-(n_size/2+1));
    }
    else{
        // 半分未満の場合
        return solve(n-1, x-1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    ll n, x; cin >> n >> x;
    bp[0] = make_pair(0, 1);
    repf(i, 50){
        bp[i].first = bp[i-1].first*2+2;
        bp[i].second = bp[i-1].second*2+1;
    }
    cout << solve(n, x) << endl;
}