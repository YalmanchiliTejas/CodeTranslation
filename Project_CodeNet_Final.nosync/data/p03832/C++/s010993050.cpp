#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define len(x) (int)(x).size()



using namespace std;
//#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define int long long
const int N = 1e3 + 10 , MOD = (int)1e9 + 7;
int dp[2][N];

int C[N][N] , fact[N] , inv[N] , cnt[N][N], PW[N][N];
inline int sum(int x , int y){
    x += y;if(x >= MOD)x-=MOD;
    return x;
}
inline int mult(int x , int y){
    return (1ll * x * y) % MOD;
}

int pw(int a , int b){
    if(b == 0)return 1;
    int ans = pw(a , b >> 1);
    ans = mult(ans , ans);
    if(b & 1){
        ans = mult(ans , a);
    }
    return ans;
}
inline int INV(int x){
    return pw(x , MOD - 2);
}

void prec(){
    for(int i = 0 ; i < N; ++i){
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            C[i][j] = sum(C[i-1][j-1], C[i-1][j]);
        }
    }
    fact[0] = 1;
    for(int i = 1; i < N; ++i)
        fact[i] = mult(fact[i - 1] , i);
    inv[N - 1] = INV(fact[N - 1]);
    for(int i = N - 2; i >= 0;--i){
        inv[i] = mult(inv[i + 1] , i + 1);
        assert(inv[i] == INV(fact[i]));
    }



    for(int i = 0 ; i < N; ++i){
        for(int j = 1; j <= i; ++j){
            if(i % j ==0){
                cnt[i][j] = mult(mult(fact[i],pw(inv[j] , i / j)),inv[i/j]);
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    prec();
//    cout << "LULZ\n";
    int n , a , b, c , d;cin >> n >> a >> b >> c >> d;
    dp[0][0] = 1;
    int bt = 1;

    for(int i = a; i <= b; ++i){
        for(int j = 0 ; j < N; ++j){
            dp[bt][j] = dp[bt^1][j];
        }
        int l = c , r = d;
        r = min(r , n / i);
        for(int cur = l ; cur <= r; ++cur){
            for(int k = 0; k <= n - cur * i;  ++k){
                dp[bt][k + cur * i] = sum(dp[bt][k+cur*i] , (1ll*dp[bt^1][k]*C[n-k][cur*i]%MOD*cnt[cur*i][i]%MOD));
            }
        }
//        cout << " LULZ " << i << '\n';
//        for(int j = 0 ; j <= 7; ++j)
//            cout << dp[bt][j] << ' ';
//        cout << '\n';
//        cout << " WTF \n";
        bt ^= 1;
    }
    cout << dp[bt^1][n];
    return 0;
}

