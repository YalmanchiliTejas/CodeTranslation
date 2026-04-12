#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
#define int long long
int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(ll &a, ll b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
}
const int MAXN = 2e5 + 5;
int n, x, a[MAXN], lst[MAXN];
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	cin >> n >> x >> P;
	if(n <= P) {
		int res = x;
		For(i, 2, n) {
			x = 1ll * x * x % P; res += x;
		}
		cout<< res <<endl;
	} else {
		a[1] = x % P; lst[x] = 1;
		int st = 0, len = 0, res = 0, t = 0, f = 0;
		For(i, 2, 2 * P) {
			a[i] = 1ll * a[i-1] * a[i-1] % P;
//			cerr << a[i] <<' ' << a[i-1] << endl;
			if(!lst[a[i]]) lst[a[i]] = i;
			else {
				if(f) continue;
				f = 1;
				st = lst[a[i]], len = i - lst[a[i]]; 
				For(j, lst[a[i]] + 1, i) t += a[j];
			}
		}
//		cerr << st <<' ' <<len<< ' ' << t <<endl;
//		For(i, 1, 2 * P) cerr << a[i] << ' ';
//		cerr << endl;
		For(i, 1, st) res += a[i];
		res += ((n - st) / len) * t;
		foR(i, n, n - (n - st) % len + 1) {
//			cerr << i << endl;
			res += a[st + ((i - st) % len)];
		}
		cout << res <<endl;
	}
	
    return FastIO::Fflush(), 0;
}
/*

*/

