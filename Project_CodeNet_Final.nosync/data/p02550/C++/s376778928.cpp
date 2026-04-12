#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    ll n, x, m; cin >> n >> x >> m;
    
    ll res = 0;
    vector<int> memo, index(m, INF); //index:その数が何番目に出てきたか
    int i = 0;
    for(i; i<n; i++){
        if(index[x]!=INF)break; //既出の数が出たらループを抜ける
        memo.push_back(x);
        index[x] = i;
        res += x;
        x = (x*x)%m;
    }
    if(i<n){
        ll rsiz = i - index[x];
        ll sum = 0;
        rept(j, index[x], memo.size()){
            sum += memo[j];
        }
        ll count = n - i;
        res += sum * (count / rsiz);
        rep(j, count % rsiz){
            res += memo[j + index[x]];
        }
    }
    
    cout << res << ln;
}

