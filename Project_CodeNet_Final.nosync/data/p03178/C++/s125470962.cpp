#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int K = 10005;
const int D = 105;

string k;
int memo[K][D][2], d, n;
bool vis[K][D][2];

int dp(int idx, int sum, bool p){
    if(idx == n){
        if(sum == 0) return 1;
        return 0;
    }

    if(vis[idx][sum][p]) return memo[idx][sum][p];
    vis[idx][sum][p] = true;

    int ans = 0, r;
    for(int i = 0; i < 10; i++){
        r = 0;
        if(p && k[idx] - '0' == i) r = dp(idx + 1, (sum + d - i) % d, true);
        else if(!p || k[idx] - '0' > i) r = dp(idx + 1, (sum + d - i) % d, false);

        ans += r;
        ans %= mod;

        //f(idx == 0) cout << i << " " << r << endl;
    }

    return memo[idx][sum][p] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> d;
    n = k.size();
    
    cout << (dp(0, 0, true)  - 1 + mod) % mod << endl;
}