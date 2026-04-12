#include <fstream>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define ll long long
#define pii pair<int,int>
#define add(a,b) ((int) (((ll) (a) + (b))%MOD))
#define mul(a,b) ((int) (((ll) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, S, a;
int dp [3000][3001] = {{0}};

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    F0R(i,N) {
        cin >> a;
        if (a <= S) dp[i][a] = i+1;
        if (!i) continue;
        FOR(j,1,S+1) {
            if (j-a > 0) dp[i][j] = add(dp[i][j], dp[i-1][j-a]);
            if (j != S) dp[i][j] = add(dp[i][j], dp[i-1][j]);
        }
    }
    int ans = 0;
    RF0(i,N) ans = add(ans,mul(dp[i][S], N-i));
    cout << ans << '\n';
}