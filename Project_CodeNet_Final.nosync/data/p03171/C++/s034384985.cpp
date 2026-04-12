#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll ;

const ll inf = 1e12 + 17;
const int maxn = 3e3 + 10;
const int maxq = 1e2 + 10;
const int alf = 26;
const ll dlm = 1e9 + 7;
const int del = 998244353 ;
const int eps = 1e-7 ;

ll dp1[maxn][maxn];
ll dp2[maxn][maxn];
//      i      j
ll a[maxn];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int dif=0;dif<n;dif++){
        for(int i=1;i<=n;i++){
            int j = i + dif;
            if(j>n)break;
            if(i==j){
                dp1[i][j] = a[i];
                dp2[i][j] = -a[i];
            }
            dp2[i][j] = min(dp1[i+1][j]-a[i] , dp1[i][j-1]-a[j]);
            dp1[i][j] = max(dp2[i+1][j]+a[i] , dp2[i][j-1]+a[j]);
        }
    }
    cout<<dp1[1][n];
    return 0;
}
