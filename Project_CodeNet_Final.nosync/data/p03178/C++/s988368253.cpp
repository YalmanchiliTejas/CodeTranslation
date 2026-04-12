/// WA

#include<bits/stdc++.h>
     
#define x first
#define y second
#define pb push_back
#define sz(x) (int) x.size()

using namespace std;

using ll = long long;
using pii = pair<int, int>;                                   

const int MOD = 1e9 + 7;
const int INF32 = 1e9 + 1e2;

void stndrtin() {
#ifdef ADIL    
    freopen(".in", "r", stdin);
#endif
}
              
const int N = 1e4+10;

ll dp[2][N], nw[2][N];

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr), stndrtin();        
    string k;
    cin >> k;
    int d;
    cin >> d;
    dp[0][0] = 1;
    for (int i = 0; i < sz(k); ++i) {
        for (int w = 0; w < d; ++w) {
            for (bool t : {0, 1}) {
                for (int x = 0; x < 10; ++x) {
                    if (x > k[i]-'0' && !t) 
                        break;  
                    add(nw[t || (x < k[i]-'0')][(w+x)%d], dp[t][w]);
                }              
            }
        }
        for (bool t : {0, 1}) 
            for (int w = 0; w < d; ++w) {
                dp[t][w] = nw[t][w];
                nw[t][w] = 0;
            }
    }
    cout << (dp[0][0] + dp[1][0] - 1 + MOD) % MOD;
    return 0;
}