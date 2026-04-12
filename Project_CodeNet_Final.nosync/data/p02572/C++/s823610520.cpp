#include<bits/stdc++.h>
 
using namespace std;

#define debug(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;

#define N 200005
lli a[N];

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n; i++) cin >> a[i];
    lli ans = a[0]*a[1];
    lli sum = a[0]+a[1], mod = 1e9+7;
    for(int i=2; i<n; i++){
		ans = (ans + sum*a[i])%mod;
		sum = (sum+a[i])%mod;
	}
	cout << ans%mod << endl;
 
    return 0;
}
