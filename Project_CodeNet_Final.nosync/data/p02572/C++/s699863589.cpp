 #include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
const ll inf =1e17;
typedef unsigned long long ull;
#define scn(a) scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define scl(a) scanf("%lld",&a)
#define ptf(a) printf("%d\n",a)
#define mes(a,b) memset(a,b,sizeof(a))
#define fon(s,n) for(int i=s;i<=n;i++)
#define range(i,a,b) for(int i=a;i<=b;++i)
#define rerange(i,a,b) for(int i=a;i>=b;--i)
//#define N 100010
//const ll p =998244353;
//const int S=20;
ll gcd(ll a,ll b) { return b>0 ? gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll q_pow(ll a,ll b,ll mod)
{
	ll ans=1,res=a;
	while(b){
		if(b&1) ans=ans*res%mod;
		res=res*res%mod;
		b>>=1;
	}
	return ans%mod;
}
//ll a[100005];
//int cnt[105]={0};
//char s[1005];
//char t[1005];
ll a[200005];
ll an[200005];
const ll modp=1e9+7;
int main()
{
	//int a, b, c, d, n, t;
	//int t;
	// //double n,m,x,y;
	// scn(t);
	// while (t--)
	// {
	// 	int n;scn(n);
	// 	for(int i=0;i<n;i++) scl(a[i]);
	// 	sort(a,a+n);
	// 	ll ans1=a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5];
	// 	ll ans2=a[n-1]*a[n-2]*a[n-3]*a[1]*a[0];
	// 	ll ans3=a[n-1]*a[3]*a[2]*a[1]*a[0];
	// 	ll ans=max(ans1,ans2);
	// 	ans=max(ans,ans3);
	// 	printf("%lld\n",ans);
	// }
	int n;scn(n);
	ll ans=0;

	for(int i=0;i<n;i++)scl(a[i]);
	an[0]=a[0];
	for(int i=1;i<n;i++)an[i]=an[i-1]+a[i];
	for(int i=0;i<n;i++){
		ans+=(((an[n-1]-an[i])%modp)*(a[i]%modp))%modp;
	}
	ans%=modp;
	printf("%lld",ans);
	return 0;
}



