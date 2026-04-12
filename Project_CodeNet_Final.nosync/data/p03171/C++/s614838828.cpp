#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const int N = 3010;
ll dp[N][N];

int main() {
    int n;
    cin >> n;
    VL a(n);
    REP(i,n) a[i] = in();
    REP(i,n){
        if (n % 2) dp[i][i] = a[i];
        else dp[i][i] = -a[i];
    }
    FORR(t,n-2,0){
        int len = n - t;
        REP(i,n-len+1){
            int j = i + len - 1;
            if (t % 2 == 0){
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
            }else{
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j]);
            }
        }
    }

    cout << dp[0][n-1] << endl;
    return 0;
}
