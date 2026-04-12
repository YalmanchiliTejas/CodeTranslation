#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll ;

const ll inf = 1e9 + 10;
const int maxn = 3e3 + 10;
const int maxq = 6e2 + 10;
const int alf = 26;
const ll dlm = 1e9+7;
const int del = 1234234 ;
const int eps = 1e-7 ;
string O[]={"YES","NO","Yes","No"};

ll dp[maxn][maxn];
ll a[maxn];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            ll len = j-i + 1;
            if((len%2)==(n%2)){
                dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
            }else{
                dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
