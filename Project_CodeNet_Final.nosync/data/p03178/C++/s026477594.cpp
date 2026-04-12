#include <bits/stdc++.h>
#define va first
#define vb second
#define lb lower_bound
#define pb push_back
#define all(v) v.begin(),v.end()
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll = long long;
using lf = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod = 1e9 + 7;

int m;
string K;
int n;

ll d[10005][105];

inline void add(ll &x, ll y){
    x = (x + y) % mod;
}

void build(){
    for(int j = 0; j < 10; j++) (++d[0][j%m]) %= mod;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 10; k++){
                add(d[i][(j + k) % m], d[i-1][j]);
            }
        }
    }
}

ll dp(int i, int v){
    if(!i){
        ll c = 0;
        for(int j = 0; j <= K[i]; j++) if(j % m == v) ++c;
        return c;
    }
    ll ans = 0;
    for(int j = 0; j < K[i]; j++){
        add(ans, d[i-1][(v + m - (j%m)) % m]);
    }
    return (ans + dp(i-1, (v+m-(K[i]%m)) % m)) % mod;
}

int main(){
    fio;
    cin >> K >> m;
    n = K.size();
    for(int i = 0; i < n; i++) K[i] -= '0';
    build();
    reverse(K.begin(),K.end());
    cout << (dp(n-1,0) + mod - 1) % mod << '\n';
/*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << d[i][j] << ' ';
        cout << '\n';
    }
*/
}