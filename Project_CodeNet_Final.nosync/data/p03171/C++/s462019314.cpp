#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define DIM (long long)3007
#define INF (long long)100000007

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;

ll n,m,i,j,sum,f1,f2,v1,v2,k,x,y,l;
ll a[DIM];
ll dp[DIM][DIM];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(i=1; i<=n; i++) cin >> a[i];

    for(l=1; l<=n; l++){
        for(i=1; i<=n-l+1; i++){
            dp[l][i]=max(a[l+i-1]-dp[l-1][i],a[i]-dp[l-1][i+1]);

        }
    }

    cout << dp[n][1] << endl;










    return 0;
}
