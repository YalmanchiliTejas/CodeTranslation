#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

const int mod = 1000000000 + 7;

string K;
int D;
ll dp[10100][110][2];

ll rec(int pos, int rem, int is_less){
    if(dp[pos][rem][is_less] >= 0) return dp[pos][rem][is_less];
    ll res = 0;
    if(pos == (int)K.size()) res = (rem == 0);
    else{
        if(is_less){
            // 任意の数字を選べる
            for(int i = 0; i < 10; i++) 
                (res += rec(pos + 1, (rem + i) % D, is_less)) %= mod;
        }
        else{
            // 自分より小さい数字
            for(int i = 0; i < K[pos] - '0'; i++)
                (res += rec(pos + 1, (rem + i) % D, 1)) %= mod;
            // 同じ数字
            (res += rec(pos + 1, (rem + (K[pos] - '0')) % D, is_less)) %= mod;
        }
    }
    return dp[pos][rem][is_less] = res;
}

int main() {

    cin >> K;
    cin >> D;
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, 0, 0) - 1 + mod) % mod << endl;

    return 0;
}
