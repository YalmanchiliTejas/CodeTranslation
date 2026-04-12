#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
typedef long long LL;
const int maxn = 105;
const LL mod = 1e9 + 7;

int n, h[maxn];
struct Node {
	LL x, y;
};
LL ans;

LL Ksm(LL a, LL b) {
	LL ans = 1;
	while(b) {
		if(b&1) ans = ans*a%mod;
		b /= 2;
		a = a*a%mod;
	}
	return ans;
}

Node Solve(int l, int r, int bot) {
	int cnt = 0, low = 1e9;
	Node ans;
	rep(i, l, r) 
	    low = min(low, h[i]);
	rep(i, l, r)
	    if(h[i] == low) cnt++;
	if(cnt == r - l + 1) {
		if(!low) return (Node) {1, 1};
		ans.y = Ksm(2, low - bot);
		ans.x = (Ksm(2, r - l + 1) + Ksm(2, low - bot) - 2)%mod;
		return ans; 
	}
	LL c1 = 1, c2 = 1;
	rep(i, l, r) {
		if(h[i] == low) continue;
		int cur = i;
		while(h[cur + 1] > low && cur < r) cur++;
		Node res = Solve(i, cur, low);
		i = cur;
		c2 = c2*res.y%mod;
		c1 = c1*(res.x + res.y)%mod;
	}
	c1 = (c1*Ksm(2, cnt)%mod + c2*(Ksm(2, low - bot) - 2 + mod)%mod)%mod;
	c2 = c2*Ksm(2, low - bot)%mod;
	return (Node) {c1, c2};
}

int main() {
	cin>>n;
	rep(i, 1, n) 
	    cin>>h[i];
	ans = 1;
	for(int i = 1; i <= n; i++)
    	if(h[i] > max(h[i - 1], h[i + 1])) {
    		ans = ans*Ksm(2, h[i] - max(h[i - 1], h[i + 1]))%mod;
            h[i] = max(h[i - 1], h[i + 1]);
    	}
	Node tmp = Solve(1, n, 0);
	cout<<(ans*tmp.x%mod + mod)%mod<<endl;
}