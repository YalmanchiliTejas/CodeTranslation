#include <bits/stdc++.h>
#define mod 1000000007
#define fir first
#define sec second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int add(int x,int y){
	x += y;if (x >= mod) x -= mod;
	return x;
}

inline int sub(int x,int y){
	x -= y;if (x < 0) x += mod;
	return x;
}
inline int qpow(int x,int y){
	int res = 1;
	while (y){
		if (y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}
const int N = 1e5 + 10;

int n , h[N];
pii solve(int l,int r,int lim){//first not ababab second ababa
	int minm = 0x3f3f3f3f , cntminm = 0 , block = 0;
	for (int i = l;i <= r;i++){
		if (h[i] < minm){
			minm = h[i];
			cntminm = 0;
		}
		if (h[i] == minm) cntminm++;
	}
	
	if (cntminm == r - l + 1){
//		printf("%d %d %d [%d %d]\n",l,r,lim,qpow(2,r-l+1)-2,qpow(2,h[l]-lim));
		return mp(qpow(2 , r - l + 1) - 2 , qpow(2 , h[l] - lim));
	}
	
	pii res = mp(1 , 1);
	for (int i = l;i <= r;i++){
		if (h[i] == minm) continue;
		int j = i;while (j + 1 <= r && h[j + 1] != minm)j++;
		
		pii tmp = solve(i , j , minm);
		res.first = 1ll * res.first * add(tmp.first , 2ll * tmp.second % mod) % mod;
		res.second = 1ll * res.second * tmp.second % mod;
		block++;
		i = j;
	}
	
	res.first = 1ll * qpow(2 , cntminm) * res.first % mod;
	res.first = sub(res.first , 2ll * res.second % mod);
	res.second = 1ll * qpow(2 , minm - lim) * res.second % mod;
	
//	printf("%d %d %d %d %d\n",l,r,lim,res.fir,res.sec);
	return res;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> h[i];
	pii res = solve(1 , n , 0);
	
	cout<<add(res.first,res.second);


	return 0;
}