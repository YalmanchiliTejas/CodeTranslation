#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(2e5 + 5);
const double EPS = 1e-8;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

ll n, a[3005], dp[3005][3005];

ll rec(bool turn, int i, int j){
    if(i>j) return 0;
    if(dp[i][j]<LLINF) return dp[i][j];
    ll res = (turn?LLINF:-LLINF);
    if(turn){
        res = max(rec(!turn,i+1,j)+a[i],rec(!turn,i,j-1)+a[j]);
    }
    else{
        res = min(rec(!turn,i+1,j)-a[i],rec(!turn,i,j-1)-a[j]);
    }
    dp[i][j] = res;
    return res;
}

int main() {
    cin >> n;
    REP(i,n) cin >> a[i];
    REP(i,n)fill(dp[i],dp[i]+n,LLINF);
    cout << rec(true,0,n-1) << endl;
    return 0;
}
