#include<bits/stdc++.h>
#define ull unsigned long long
#define lowbit(x) ((x)&(-x))
#define dis(p,q) sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y))

#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;

namespace _{
    bool rEOF = 1;//为0表示文件结尾
    inline char nc(){
        static char buf[100000], *p1 = buf, *p2 = buf;
        return p1 == p2&&rEOF && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? (rEOF = 0, EOF) : *p1++;
    }
    template<class _T>
    inline bool read(_T &num){
        char c = nc(), f = 1; num = 0;
        while (c<'0' || c>'9')c == '-' && (f = -1), c = nc();
        while (c >= '0'&&c <= '9')num = num * 10 + c - '0', c = nc();
        return (bool)(num *= f);
    }
    inline bool need(char &c){ return c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z'; }//读入的字符范围
    inline bool read_str(char *a){
        while ((*a = nc()) && need(*a) && rEOF)++a;
        *a = '\0'; return rEOF;
    }
}using namespace _;

const int N = 2e5+10;		//复杂度O(n)
const ll mod = 1e9 + 7;
int F[N+5], Finv[N+5], inv[N+5];//F是阶乘，Finv是阶乘的逆元
//X 关于 mod 的逆元为 x^(mod - 2);
void init(){
	F[0] = Finv[0] = inv[1] = 1;
	for (register int i = 2; i <= N; i++)
		inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
	for (register int i = 1; i <= N; i++){
		F[i] = F[i - 1] * 1ll * i % mod;
		Finv[i] = Finv[i - 1] * 1ll * inv[i] % mod;
	}
}
int comb(int n, int m){///comb(n, m)就是C(n, m)
	if (m < 0 || m > n) return 0;
	return F[n] * 1ll * Finv[n - m] % mod * Finv[m] % mod;
}

int main()
{
    ll n,m,k;
    init();
    scanf("%lld%lld%lld",&n,&m,&k);
    ll ans=0;
    for(ll i=1;i<n;i++)
    {
        ans+=(((((m*m*(n-i))%mod)*i)%mod)*comb(m*n-2,k-2))%mod;
        ans%=mod;
    }
    for(ll i=1;i<m;i++)
    {
        ans+=(((((n*n*(m-i))%mod)*i)%mod)*comb(m*n-2,k-2))%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}
