#include<bits/stdc++.h>
#define For(i,l,r) for(int i = (l),i##end = (r);i <= i##end;i++)
#define Fordown(i,r,l) for(int i = (r),i##end = (l);i >= i##end;i--)
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;

template <typename T> inline bool chkmin(T &x,T y) { return y < x ? x = y,1 : 0; }
template <typename T> inline bool chkmax(T &x,T y) { return x < y ? x = y,1 : 0; }

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10,mod = 1e9 + 7;

char str[N];
int dp[N];

inline int read() {
	int x = 0,flag = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') flag = -1,ch = getchar();
	while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch - '0'),ch = getchar();
	return x * flag;
}

inline void Add(int &x,int y) { if((x += y) >= mod) x -= mod; }
inline int chk(int v) { return v < 0 ? 0 : dp[v]; }
inline int val(int v) { return v & 1 ? v - 1 : v; }

int main() {

	int n = read(),m = read(),flag = true;
	scanf("%s",str + 1);
	For(i,1,m - 1) if(str[i] != str[i + 1]) flag = false;
	if(flag) {
		int v00 = 1,v11 = 1,v01 = 0,v10 = 0;
		For(i,2,n) {
			int c00 = v00,c10 = v10;
			Add(v00,v10),Add(v10,v11);
			v01 = c00,v11 = c10;
		}
		printf("%lld\n",(1ll * v00 + v10 + v01) % mod);
		return 0;
	}
	if(n & 1) return puts("0"),0;
	int v = INF,tot = 0;
	For(i,1,m) {
		if(str[i] == str[1]) tot++;
		else {
			if(tot == i - 1) chkmin(v,tot + (tot % 2 == 0));
			if(tot & 1) chkmin(v,tot);
			tot = 0;
		}
	}
	v++, dp[0] = 1;
	for(int i = 2;i <= n;i += 2) dp[i] = (2ll * dp[i - 2] - chk(i - 2 - v)) % mod;
	int ans = dp[n] - dp[n - 2];
	For(i,1,v - 1) ans = (ans + 1ll * dp[val(n - i - 1)] - dp[n - v - 2]) % mod;
	printf("%d\n",(ans + mod) % mod);
	return 0;
}