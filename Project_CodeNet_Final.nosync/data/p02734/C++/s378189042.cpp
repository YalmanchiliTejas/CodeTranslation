//
//  main.cpp
//  CP
//
//  Created by Shiv Pavan Raj on 22/02/20.
//  Copyright © 2020 Shiv Pavan Raj. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)(x).size())
using namespace std;
typedef pair<int,int> PII;
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define REP(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define M 1000000007
#define MM 998244353
#define SZ(a) int((a).size())
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define mod 998244353
//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p; }

using ll = long long;
using VI = vector<int>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using VLL = vector<ll>;
using ld = long double;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
      
}

const int MX = 5e6+10;
const int MX2 = 1e6+5;

ll INF= 4 * (ll)1e18;


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0); // insert code here...
    int N,S;
    cin >> N >> S;
    int A[N+10];
    FOR(i,1,N) cin >> A[i];
    int ans =0;
    vector<vector<int> > dp(N+4,vector<int>(S+4,0));
    
    FOR(i,1,N) {
        FOR(j,1,S) {
            if (j == A[i]) dp[i][A[i]] = add(i,dp[i - 1][A[i]],mod);
            else if (A[i] < j) {
                dp[i][j] = add(dp[i][j],dp[i - 1][j - A[i]],mod);
                dp[i][j] = add(dp[i][j],dp[i - 1][j],mod);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    FOR(i,1,N) {
        ans = add(ans,mul(dp[i][S],1,mod),mod);
    }
    cout << ans << endl;
    return 0;
    
}





