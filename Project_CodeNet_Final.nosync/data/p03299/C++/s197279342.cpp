#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 105;

int n, h[N];
LL ans = 1, mod = 1e9 + 7;
struct node {
	LL x, y;
};

LL fsp(LL a, LL b) {
	LL rst = 1;
	while(b > 0) {
		if(b&1) rst = rst*a%mod;
		b = b>>1;
		a = a*a%mod;
	}
	return rst;
}

node solve(int l, int r, LL up) {
	int cnt = 0, mi = 1e9 + 5, last = 0;
	node rst;
	for(int i = l; i <= r; i++)
		if(h[i] == mi) cnt++;
	    else if(h[i] < mi) mi = h[i], cnt = 1;
	if(cnt == r - l + 1) {
		rst.x = (fsp(2, mi - up) + fsp(2, r - l + 1) - 2 + mod)%mod;
		rst.y = fsp(2, mi - up);
		return rst;
	}
	LL c1 = 1, c2 = 1;
	for(int i = l; i <= r + 1; i++) {
		if(h[i] > mi && !last) last = i;
		else if(h[i] == mi || i > r) {
			if(!last) continue;
			node tmp = solve(last, i - 1, mi);
			c1 = c1*(tmp.x + tmp.y)%mod;
			c2 = c2*tmp.y%mod;
			last = 0;
		} 
	}
	c1 = (c1*fsp(2, cnt)%mod + c2*(fsp(2, mi - up) - 2 + mod)%mod)%mod;
	c2 = c2*fsp(2, mi - up)%mod;
	rst = (node) {c1, c2};
	return rst;
}

int main() {
    cin>>n;
    for(int i = 1; i <= n; i++) 
    	cin>>h[i];
    for(int i = 1; i <= n; i++)
    	if(h[i] > max(h[i - 1], h[i + 1])) {
    		ans = ans*fsp(2, h[i] - max(h[i - 1], h[i + 1]))%mod;
            h[i] = max(h[i - 1], h[i + 1]);
    	}
    node tmp = solve(1, n, 0);
    cout<<tmp.x*ans%mod<<endl;
	return 0;
}