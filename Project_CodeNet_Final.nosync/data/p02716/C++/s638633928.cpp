#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

int n;
ll a[N], f[N], sum;

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		if(i&1) sum += a[i];
		if(i == 1) continue;
		if(i&1) f[i] = max(f[i - 2] + a[i], f[i - 1]);
		else f[i] = max(f[i - 2] + a[i], sum);
	}
	cout<<f[n]<<endl;
}
