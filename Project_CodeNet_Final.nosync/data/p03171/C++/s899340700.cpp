#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n;cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];

    vector<vl> dp(n+10, vl(n+10,0));
    rep(i,n) dp[i][i] = a[i];

    for(int inter=1;inter<=n;++inter){
        for(int l=0;l<n;++l){
            int r = l + inter -1;
            if(r>=n) continue;

            if(inter&1){
                dp[l][r] = max((r!=0? dp[l][r-1] : 0) + dp[r][r] , (l!=n-1? dp[l+1][r] : 0) + dp[l][l]);
            }else{
                dp[l][r] = min((r!=0? dp[l][r-1] : 0) - dp[r][r] , (l!=n-1? dp[l+1][r] : 0) - dp[l][l]);
            }
        }
    }
    cout << ((n&1)?dp[0][n-1] : -dp[0][n-1]) << endl;
}