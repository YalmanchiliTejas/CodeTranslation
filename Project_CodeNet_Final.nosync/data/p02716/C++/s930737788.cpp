#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i,n)cin >> a[i];
    ll b[n], c[n];
    drep(i,n){
        if(i % 2 == 0){
            if(i + 2 >= n)b[i] = a[i];
            else b[i] = b[i+2] + a[i];
        }else{
            if(i + 2 >= n)c[i] = a[i];
            else c[i] = c[i+2] + a[i];
        }
    }
    ll sum[n] = {};
    rep(i,n){
        if(i <= 1)sum[i] = a[i];
        else sum[i] = sum[i-2] + a[i];
    }

    ll ans = -1001001001001001001;

        

    if(n % 2 == 0){
        ans = max(sum[n-1], sum[n-2]);
        srep(i,2,n){
            if(i % 2 == 1)continue;
            ans = max(ans, sum[i-2] + c[i+1]);
        }
    }else{
        ll dp[n];
        rep(i,n)dp[i] = -1001001001001001001;
        rep(i,n){
            if(i <= 1)dp[i] = a[i];
            else{
                if(i % 2 == 0){
                    dp[i] = dp[i-2] + a[i];
                }else{
                    dp[i] = max(dp[i-2], dp[i-3]) + a[i];
                }
            }
        }
        ll pd[n];
        rep(i,n)pd[i] = -1001001001001001001;
        drep(i,n){
            if(i + 2 >= n)pd[i] = a[i];
            else{
                if(i % 2 == 0){
                    pd[i] = pd[i+2] + a[i];
                }else{
                    pd[i] = max(pd[i+2], pd[i+3]) + a[i];
                }
            }
        }
        rep(i,n){
            if(i % 2 == 1)continue;
            ll tmp = 0;
            if(i >= 2){
                tmp += max(dp[i-1], dp[i-2]);
            }
            if(i + 2 < n){
                tmp += max(pd[i+1], pd[i+2]);
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}
 
 
