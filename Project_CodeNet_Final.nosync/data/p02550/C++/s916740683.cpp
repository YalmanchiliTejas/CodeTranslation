#include<bits/stdc++.h>
#define int long long
using namespace std;
int Read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-')  f = -1; ch = getchar();}
	while(isdigit(ch)) {x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
	return x * f;
}
map<int, int> mp;
int cnt, ccnt, ori, xh[100005];
signed main() {
	int n = Read(), x = ori = Read(), m = Read();
	if(n <= m + 1) {
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans += x, x = x * x % m;
		cout << ans << endl;
		return 0;
	}
	for(int i = 1; ; i++) {
		if(mp[x]) {ccnt = i - 1; cnt = mp[x]; break;}
		mp[x] = i;
		x = x * x % m;
	}
	x = ori; int ans = 0, sum = 0;
	for(int i = 1; i <= ccnt; i++) {
		if(i < cnt)  ans += x;
		else  xh[i - cnt + 1] = x, sum += x;
		x = x * x % m;
	}
	n = n - cnt + 1;
	int div = n / (ccnt - cnt + 1), md = n % (ccnt - cnt + 1);
	ans += div * sum;
	for(int i = 1; i <= md; i++)  ans += xh[i];
	cout << ans << endl;
	return 0;
}