#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(_i,_a,_n) for(int _i=_a;_i<=_n;++_i)
#define PER(_i,_a,_n) for(int _i=_n;_i>=_a;--_i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(_a) ({REP(_i,1,n) cout<<_a[_i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 998244353;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head


const int N = 1e7+10;
int n, fac[N], ifac[N], po[N];
int C(int n, int m) {
	return (ll)fac[n]*ifac[m]%P*ifac[n-m]%P;
}

int main() {
	fac[0] = po[0] = 1;
	REP(i,1,N-1) fac[i]=(ll)fac[i-1]*i%P,po[i]=(ll)po[i-1]*2%P;
	ifac[N-1] = inv(fac[N-1]);
	PER(i,0,N-2) ifac[i]=(ll)ifac[i+1]*(i+1)%P;
	scanf("%d", &n);
	int ans = qpow(3,n);
	REP(i,n/2+1,n) ans = (ans-2ll*C(n,i)*po[n-i])%P;
	if (ans<0) ans += P;
	printf("%d\n", ans);
}






