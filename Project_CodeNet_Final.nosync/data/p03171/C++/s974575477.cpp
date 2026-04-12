// g++ -std=c++11 -O2 -Wall -Wl,--stack=268435456

#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector< vi >       vvi;
typedef pair<int, int>     pi;
typedef vector< pi >       vpi;

typedef vector<ll>         vl;
typedef vector< vector <ll> >   vvl;

#define LARGE_INT     1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = (int)(a); i < (int)(b); i++)

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int  n;
    cin >> n;
    vi a(n);
    vvl dp(n, vl(n, 0));  // dp[i][j]  game outcome with j to j+i left, 
    
    REP(j, 0, n) { cin >> a[j]; }
    int sign = (n % 2) * 2 - 1;  // the n-th stone is odd -> 1, even -> -1
    REP (j, 0, n) {  
        dp[0][j] = sign * a[j];
    }
    REP(i, 1, n) REP(j, 0, n-i) {
        if ((n-i) % 2 == 1) { // next stone is odd, first player's turn
            dp[i][j] = max(a[j] + dp[i-1][j+1], a[j+i] + dp[i-1][j]);
        } else {
            dp[i][j] = min(-a[j] + dp[i-1][j+1], -a[j+i] + dp[i-1][j]);
        }
    }
    /*
    REP(i, 0, n) {
        REP(j, 0, n-i)   cout << dp[i][j] << " ";
        cout << endl;
    }*/
    cout << dp[n-1][0];
    return 0;
}