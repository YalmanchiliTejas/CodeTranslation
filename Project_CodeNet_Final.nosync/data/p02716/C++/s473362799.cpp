#include <iostream>

using namespace std;
typedef long long ll;
ll a[200010],dp1[200010][2],dp2[200010][2];
int main(){
    int i,n;
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    dp1[0][0] = dp1[0][1] = 0;
    dp2[n][0] = dp2[n][1] = 0;
    for(i=2;i<=n;i+=2){
        dp1[i][0] = dp1[i - 2][0] + a[i - 2];
        dp1[i][1] = max(dp1[i - 2][0],dp1[i - 2][1]) + a[i - 1];
    }
    for(i=n - 2;i>=0;i-=2){
        dp2[i][0] = dp2[i + 2][0] + a[i + 1];
        dp2[i][1] = max(dp2[i + 2][0],dp2[i + 2][1]) + a[i];
    }
    if(n%2==0){
        cout << max(dp1[n][0],dp1[n][1]) << endl;
    }else{
        ll ans = -10000000000000000;
        for(i=0;i<n;i+=2){
            ans = max(ans,max(dp1[i][0],dp1[i][1]) + max(dp2[i + 1][0],dp2[i + 1][1]));
        }
        cout << ans << endl;
    }
}