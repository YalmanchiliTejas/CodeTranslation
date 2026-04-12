#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i,n)cin >> a[i];
    ll dp[n+100][n+100];
    srep(i,1,n+1){
        rep(j,n+1-i){
            if(n<=j+i-1){
                dp[i][j] = -10000000070000;
                continue;
            }
            if(i==1){
                dp[i][j] = a[j];
            }else{
                ll left = a[j] - dp[i-1][j+1];
                ll right = a[j+i-1] - dp[i-1][j];
                dp[i][j] = max(left,right);
            }
        }
    }
    
    cout << dp[n][0] << endl;

    return 0;
}
 
 
