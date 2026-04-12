#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

ll a[N], ans, sum[N], f[N];
int n;


int main() {
	cin>>n; 
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if(i > 1) sum[i] = sum[i - 2] + a[i];
		else sum[i] = a[i];
	}
	for(int i = 2; i <= n; i++) {
		if(i&1) f[i] = max(f[i - 2] + a[i], f[i - 1]);
		else f[i] = max(f[i - 2] + a[i], sum[i - 1]); 
 	}
 	cout<<f[n]<<endl;
}
