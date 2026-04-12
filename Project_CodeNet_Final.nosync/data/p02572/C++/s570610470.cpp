#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define mp make_pair
// GCD inbuilt func: __gcd(a,b)
// LCM formula: (a*b)/__gcd(a,b)

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	// CODE goes here
    ll n;
    cin >> n;
    ll a[n],prefix[n];
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	prefix[i]=0;
    }
    prefix[0]=a[0];
    for(int i=1;i<n;i++) prefix[i]=(prefix[i-1]+a[i])%1000000007;
    ll sum=0;
    for(int i=1;i<n;i++){
        sum+=(((a[i]%1000000007)*(prefix[i-1]%1000000007))%1000000007);
    }
    cout << sum%1000000007;
	return 0;
}
