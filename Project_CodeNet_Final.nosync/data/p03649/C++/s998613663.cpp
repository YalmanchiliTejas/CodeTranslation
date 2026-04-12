#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int MAXN = 55;

int n;
lint a[MAXN];

void simulate(){
	for(int i=0; i<n-1; i++) a[i]++;
	a[n-1] -= n;
	sort(a, a+n);
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	lint ans = 0;
	for(int i=n-1; i; i--){
		if(a[i-1] <= a[i] - n - 1){
			lint fast_step = (a[i] - a[i-1]) / (n+1);
			for(int j=i; j<n; j++) a[j] -= fast_step * (i + 1);
			for(int j=0; j<i; j++) a[j] += fast_step * (n - i);
			ans += fast_step * (n-i);
		}
	}
	lint fast = a[0] / n - 5;
if(fast > 0){
	for(int i=0; i<n; i++) a[i] -= fast * n;
	ans += fast * n * n;
}
	sort(a, a+n);
	while(a[n-1] >= n) simulate(), ans++;
	cout << ans;
}
