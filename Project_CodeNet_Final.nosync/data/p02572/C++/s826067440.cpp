#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
const int N = 3e5 + 5;

LL a[N], ans;
int n;

int main() {
	cin>>n;
	rep(i, 1, n) {
		cin>>a[i];
		ans = (ans + a[i - 1]*a[i])%mod;
		a[i] = (a[i] + a[i - 1]%mod);
	}
	cout<<ans<<endl;
}