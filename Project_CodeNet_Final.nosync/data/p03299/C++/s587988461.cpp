#include <bits/stdc++.h>

using namespace std;

typedef long long L;
const int maxn = 233 , mod = 1e9 + 7 , inv2 = 500000004;
int n;
int h[maxn];
int fpw(int x , int t){
	if(!t) return 1;
	int c = fpw(x , t >> 1);
	c = (L)c * c % mod;
	if(t & 1) c = (L)c * x % mod;
	return c;
}

int ans[maxn][maxn][3];
bool vis[maxn][maxn];
int c[2];

void solve(int l , int r , int d){
	if(vis[l][r])
		return ;
	vis[l][r] = 1;
	if(l == r){
		ans[l][r][1] = fpw(2 , h[l] - d + 1);
//		cerr << l << " " << r << " " << d << " " << ans[l][r][0] << " " << ans[l][r][1] << endl;
		return ;
	}
	int minn = (int)1e9 + 10;
	for(int k = l ; k <= r ; ++ k)
		minn = min(minn , h[k]);
	int ll = l , rr = -1;
	for(int k = l ; k <= r ; ++ k)
		if(h[k] == minn){
			rr = k - 1;
			if(ll <= rr)
				solve(ll , rr , minn + 1);
			ll = k + 1;
		}
	rr = r;
	if(ll <= rr)
		solve(ll , rr , minn + 1);
	memset(c , 0 , sizeof c);
	ll = l , rr = r;
	bool first = 1;
	for(int k = l ; k <= r ; ++ k)
		if(h[k] == minn){
			rr = k - 1;
			if(ll <= rr){
				if(first){
					c[0] = ans[ll][rr][0];
					c[1] = (ans[ll][rr][1] << 1) % mod;
					first = 0;
				}
				else{
					c[0] = ((L)c[0] * ((L)2 * ans[ll][rr][1] + ans[ll][rr][0]) + (L)c[1] * (ans[ll][rr][0] + ans[ll][rr][1])) % mod;
					c[1] = (L)c[1] * ans[ll][rr][1] % mod;
				}
			}
//			cerr << k << " " << c[0] << " " << c[1] << endl;
			if(first){
				c[0] = 0;
				c[1] = 2;
				first = 0;
			}
			else
				c[0] = ((L)c[0] * 2 + c[1]) % mod;
			ll = k + 1;
//			cerr << k << " " << c[0] << " " << c[1] << endl;
		}
	rr = r;
	if(ll <= rr){
		if(first){
			c[0] = ans[ll][rr][0];
			c[1] = (ans[ll][rr][1] << 1) % mod;
			first = 0;
		}
		else{
			c[0] = ((L)c[0] * ((L)2 * ans[ll][rr][1] + ans[ll][rr][0]) + (L)c[1] * (ans[ll][rr][0] + ans[ll][rr][1])) % mod;
			c[1] = (L)c[1] * ans[ll][rr][1] % mod;
		}
	}
	ans[l][r][0] = c[0];
	ans[l][r][1] = (L)c[1] * fpw(2 , minn - d) % mod;
//	cerr << l << " " << r << " " << d << " " << ans[l][r][0] << " " << ans[l][r][1] << endl;
}
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++ i)
		cin >> h[i];
	solve(1 , n , 1);
	cout << (ans[1][n][0] + ans[1][n][1]) % mod << endl;
	return 0;
}