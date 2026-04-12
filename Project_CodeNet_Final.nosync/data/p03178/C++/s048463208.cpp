#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int d, sz;
vector<int> dig;
ll mod = 1000000007;

ll dp[10002][101][2];

ll q(int i, int m, int fl) {
    if(i == sz) {
        return (m == 0);
    }
    
    if(dp[i][m][fl] != -1) return dp[i][m][fl];
    
    int lim;
    
    if(fl) lim = 9;
    
    else lim = dig[i];
    
    ll rem = 0;
    
    for(int j = 0; j <= lim; j++) {
        int mm = (m + j + d) % d;
        int ff = fl;
        if(j < dig[i]) ff = 1;
        rem = (rem + q(i + 1, mm, ff) + mod) % mod;
    }
    
    return dp[i][m][fl] = (rem + mod) % mod;
}
int main(){
    string k;
    cin>>k;
    cin>>d;
    for(int i = 0; i < k.length(); i++) {
        dig.push_back(k[i] - '0');
    }
    sz = dig.size();
    for(int i = 0; i < 10002; i++) {
        for(int j = 0; j < 101; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
  
    ll ans = (q(0, 0, 0) + mod - 1) % mod;
    cout<<ans<<endl;
    
  return 0;
    
}
