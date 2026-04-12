#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <string>
#include <complex>

using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)
#define lowbit(x) ((x)&(-x))
//#pragma comment(linker,"/STACK:1024000000,1024000000")
#define eps 1e-2
#define sqr(x) ((x)*(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef complex<double>cp;
template<class T>inline void rread(T&num){
    num=0;T f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    num*=f;
}
const ll inf = 1e18;
const int maxn = 1e6 +10, mod = 1e9 + 7;
const double pi = acos(-1);
ll gcd (ll a, ll b)
{return ( a ? gcd(b%a, a) : b );}
void exgcd(ll a,ll b,ll &d,ll& x,ll& y)
{
    if(!b){d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
cp power(cp a, int n)
{cp p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n)
{ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod)
{ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
//head
ll n,m,r;
bool judge(ll x)
{
    ll d = max(0ll,x-n);
    if(m-2*x-d*2>=0)return true;
    else return false;

}
int main()
{

    while(~scanf("%lld",&n))
    {

        cout<<800*n-200*(n/15)<<endl;


    }
    return 0;
}
