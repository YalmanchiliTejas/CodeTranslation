#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;

//桁和
int digsum(int n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}


int main() {
    string S; cin >> S;
    ll D; cin >> D;
    ll N = S.size();

    if(N <= 7){
        ll cnt = 0;
        for(int i = 1; i <= stoll(S); i++){
            if(digsum(i) % D == 0) cnt++;
        }
        cout << cnt%MOD << endl;
        return 0;
    }
    vector<vector<vector<ll>>> DP(N, vector<vector<ll>>(10, vector<ll>(D)));
    vector<vector<ll>> SUM(N, vector<ll>(D));

    for(int i = 0; i <= 9; i++) {
        DP[0][i][i%D]++;
        SUM[0][i%D]++;
    }

    // 下からi桁目の数がjの時のdigsumが k (mod D)
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < D; k++){
                DP[i][j][(j+k)%D] = SUM[i-1][k]%MOD;
                SUM[i][(j+k)%D] += SUM[i-1][k]%MOD;
                DP[i][j][(j+k)%D]%=MOD;
                SUM[i][(j+k)%D]%=MOD;
            }
        }
    }
    ll ans = SUM[N-2][0];
    ll temp = 0;
    //cout << ans << endl;
    for(int i = N-1; i >= 0; i--){
        ll d = S[N-1-i]-48;
        for(int j = 0; j <= d; j++) {
            if(i == N-1 && j == 0) continue;
            if(j == d && i != 0) continue;
            ll n = (temp)%D;
            ans += DP[i][j][(D-n)%D]; // i桁目がjの時にDの倍数になるもの
            //cout << i << " " << j << " " << (D-n)%D << " " << DP[i][j][(D-n)%D] << endl;
            ans %= MOD;
        }
        temp += d;
    }
    cout << (ans-1+MOD)%MOD << endl;;

}