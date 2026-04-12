#include <bits/stdc++.h>
#define rei register int
using namespace std;
const int mod = 1000000007;
int ans;
int qpow(int x,int p){
	int rec(1);
	while(p){
		if(p & 1) rec = 1ll*rec * x % mod;
		p >>= 1,x = 1ll*x * x % mod;
	} return rec;
}
int main(){
	int n ; cin >> n; int cnt(0);
	for(rei i = 1;i <= n;++i) {
		int x; scanf("%d",&x); cnt = (cnt + x) % mod;
		ans = (mod - 1ll*x * x % mod + ans) % mod;
 	}	cout << (ans + 1ll*cnt * cnt % mod) * qpow(2,mod - 2) % mod; return 0;
}