#include <bits/stdc++.h>

using namespace std;

#define INF (1ll << 62)
#define pb push_back
#define ii pair<int,int>
#define OK cerr <<"OK"<< endl
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>
#define endl '\n'
  
string x;
int d;

int dp[10007][102][2];
int MOD = 1000000007;

int mod(int n) {
    return (n + MOD) % MOD;
}

int f(int ind, int r, int leq) {
    
    if(ind == x.size()) {
        return (r == 0);
    }

    int &ret = dp[ind][r][leq];
    if(ret != -1)
        return ret;

    ret = 0;
    int lim = (leq ? 9 : x[ind] - '0');
    for(int i = 0; i <= lim; i++) {
        ret += f(ind + 1, (r + i) % d, leq | (i < (x[ind] - '0')));
        ret = mod(ret);
    }

    return ret;
}

signed main () {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);


  cin >> x;


  cin >> d;

  cout << mod(f(0, 0, 0) - 1) << endl;

}