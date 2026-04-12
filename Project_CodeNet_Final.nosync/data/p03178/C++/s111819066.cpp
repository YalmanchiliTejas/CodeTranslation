#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define pb push_back

using namespace std;

const int N = 1e6 + 69, mod = 1e9 + 7, INF = 1e9;

const ll INFLL = 1e18;

ll n, k, D, x, m, answer;
ll dp[10006][101], sum[N];
string s;

int main(){

        cin >> s >> D;


        int n = s.size();

        s = '*' + s;

        for(int i = 1; i <= n; i++) sum[i] = sum[i-1], sum[i] += s[i] - '0';

        dp[n+1][0] = 1;
        for(int i = n+1; i >= 2; i--){
                for(int d = 0; d < D; d++){
                        if(!dp[i][d]) continue;
                        //cout << dp[i][d] << " " << i << " " << d << endl;
                        for(int j = 0; j <= 9; j++){
                                if(j < (s[i-1] - '0') && ((d+j) + sum[i-2])%D == 0) answer += dp[i][d], answer %= mod;
                                dp[i-1][(d+j)%D] += dp[i][d];
                                dp[i-1][(d+j)%D] %= mod;
                        }
                }
        }

        answer --; answer += mod ; answer %= mod;

        if(sum[n] % D == 0) answer++;

        answer %= mod;

        cout << answer << endl;

}
