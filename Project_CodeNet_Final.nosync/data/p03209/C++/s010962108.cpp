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

VL b, p;

ll dfs(ll x, int i){
    ll half = (b[i]+1) / 2;
    if (x <= 0) return 0;
    if (b[i] == x){
        return p[i];
    }
    else if (half == x){
        return (p[i]+1) / 2;
    }
    else if (half < x){
        return (p[i] + 1) / 2 + dfs(x-half, i-1);
    }else{
        return dfs(x-1, i-1);
    }
}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    b.resize(n+1);
    p.resize(n+1);
    b[0] = 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        b[i] = (b[i-1] * 2) + 3;
        p[i] = (p[i-1] * 2) + 1;
    }
    ll ans = dfs(x, n);
    cout << ans << endl;
    return 0;
}