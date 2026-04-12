#include <bits/stdc++.h>  
using namespace std;  
typedef long long ll; 
typedef long double ld; 
const int INF = 0x3f3f3f3f;  
const int N = 200000 + 5;
ll a[N],f[N],sum[N];

int main()
{
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i > 1)
			sum[i] = sum[i-2] + a[i];
		else
			sum[i] = a[i];
	}
	for(int i = 2; i <= n; i++){
		if(i % 2 == 1)
			f[i] = max(f[i-2]+a[i],f[i-1]);
		else
			f[i] = max(f[i-2]+a[i],sum[i-1]);
	}
	cout << f[n] << endl;
    return 0;
}