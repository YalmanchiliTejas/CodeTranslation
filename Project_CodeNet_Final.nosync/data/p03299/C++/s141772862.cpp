#include<cstdio>
#include<vector>
#define Starseven main
#define ll long long
namespace lyt {
	void read(int &x){
	char ch=getchar();int re=0,op=1;
	while(ch<'0'||ch>'9'){if(ch=='-') op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){re=(re<<3)+(re<<1)+ch-'0';ch=getchar();}
	x = re * op;
	return ;
	}
	void read(long long &x){
	char ch=getchar();long long re=0,op=1;
	while(ch<'0'||ch>'9'){if(ch=='-') op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){re=(re<<3ll)+(re<<1ll)+ch-'0';ch=getchar();}
	x = re * op;
	return ;
	}
	void write(int x){
		if(x<0){putchar('-');x=-x;}
		if(x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}//¼ÇµÃ×Ô¼º¼Ó¿Õ¸ñºÍ»»ÐÐ 
	void write(long long x){
		if(x<0){putchar('-');x=-x;}
		if(x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}//¼ÇµÃ×Ô¼º¼Ó¿Õ¸ñºÍ»»ÐÐ
	int max(int x,int y){return x<y?y:x;}
	int min(int x,int y){return x<y?x:y;}
	int abs(int x){return x<0?-x:x;}
	long long max(long long x,long long y){return x<y?y:x;}
	long long min(long long x,long long y){return x<y?x:y;}
	long long abs(long long x){return x<0?-x:x;}
	double max(double x,double y){return x<y?y:x;}
	double min(double x,double y){return x<y?x:y;}
	double abs(double x){return x<0?-x:x;}
	void swap(int &a,int &b) {a ^= b ^= a ^= b;}
	void swap(long long &a,long long &b) {a ^= b ^= a ^= b;}
	ll Power(ll a, ll b, ll p) {
		ll re = 1;
		while(b) {
			if(b & 1ll) re = (re * a) % p;
			b >>= 1ll;
			a = (a * a) % p; 
		}
		return re;
	}
	int Power(int a, int b, int p) {
		int re = 1;
		while(b) {
			if(b & 1) re = 1ll * re * a % p;
			b >>= 1;
			a = 1ll * a * a % p; 
		}
		return re;
	}
}using namespace lyt;
const int mod = 1e9 + 7;
const int N = 1e2 + 20;
int va[N], minn[N][N];

struct xyx {
	int res1, res2;
};

xyx Dfs(int l, int r, int pre_dep) {
	int judge = minn[l][r], num = 0;
	xyx re;
	std::vector<int> v;
	v.push_back(l - 1);
	for (int i = l; i <= r; i++) {
		if(va[i] == judge) {
			v.push_back(i);
			num++;
		}
	}
	v.push_back(r + 1);
	re.res1 = re.res2 = 1;
	for (int i = 0; i < num + 1; i++) {
		if(v[i] + 1 >= v[i + 1]) continue;
		xyx hack = Dfs(v[i] + 1, v[i + 1] - 1, judge);
		re.res1 = 1ll * re.res1 * hack.res1 % mod;
		re.res2 = 1ll * re.res2 * 1ll * ( (hack.res2 + 1ll * hack.res1 * 2 % mod) % mod) % mod;
	}
	xyx ans;
	ans.res1 = 1ll * Power(2, judge - pre_dep, mod) * re.res1 % mod;
	ans.res2 = (1ll * Power(2, num, mod) * re.res2 % mod + ( (mod - 2ll * re.res1) % mod + mod) % mod) % mod;
	return ans;
}

int Starseven(void) {
	int n;
	read(n);
	for (int i = 1; i <= n; i++) {
		read(va[i]);
	}
	if(n == 1) {
		int ans = Power(2, va[1], mod);
		write(ans);
		puts("");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		minn[i][i] = va[i];
		for (int j = i + 1; j <= n; j++) {
			minn[i][j] = min(minn[i][j - 1], va[j]);
		}
	}
	xyx ans = Dfs(1, n, 0);
	ans.res1 = 1ll * (ans.res1 + ans.res2) % mod;
	write(ans.res1);
	puts("");
	return 0;	
}