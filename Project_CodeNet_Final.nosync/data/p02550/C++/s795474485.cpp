#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
int main(){
	ll n, x, m, ans = 0, s = 0, l = 0, rep;
	cin >> n >> x >> m;
	bool b[m];
	fill(b, b + m, false);
	ll cur = x;
	for (int i = 0; i < m; i++){
		if (b[cur]) rep = cur;
		b[cur] = true;
		(cur *= cur) %= m;
	}
	cur = x;
	while (cur != rep){
		ans += cur;
		(cur *= cur) %= m, n--;
		if (n == 0) break;
	}
	do{
		s += cur;
		(cur *= cur) %= m, l++;
	}while (cur != rep);
	for (int i = 0; i < n % l; i++){
		ans += cur;
		(cur *= cur) %= m;
	}
	ans += s * (n / l);
	printf("%lld\n", ans);
}