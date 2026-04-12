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
int n,m,r;
int a[maxn];
char s[maxn];
bool jj(int x)
{
    int x1 = (x-1+n)%n,x2 = (x+1)%n;
    if(s[x]=='o'&&a[x]==1&&a[x1]!=a[x2])
        return false;
    if(s[x]=='o'&&a[x]==0&&a[x1]==a[x2])
        return false;
        if(s[x]=='x'&&a[x]==1&&a[x1]==a[x2])
        return false;
        if(s[x]=='x'&&a[x]==0&&a[x1]!=a[x2])
        return false;
    return true;
}
bool judge(int x,int y)
{
    a[0]=x;a[1]=y;
    for(int i=2;i<n;i++)
    {
        if(s[i-1]=='o'&&a[i-1]==1)
        {
            a[i]=a[i-2];
        }
        else if(s[i-1]=='o'&&a[i-1]==0)
        {
            a[i]=1-a[i-2];
        }
        if(s[i-1]=='x'&&a[i-1]==1)
        {
            a[i]=1-a[i-2];
        }
        if(s[i-1]=='x'&&a[i-1]==0)
            a[i]=a[i-2];
    }
    if(!jj(n-1))return false;
    if(!jj(0))return false;
    return true;

}

int main()
{

    while(~scanf("%lld",&n))
    {
        char s1 ='S',s0 = 'W';
        scanf("%s",s);
        if(judge(1,0))
        {

            for(int i=0;i<n;i++)
                if(a[i]==1)
                printf("%c",s1);
                else printf("%c",s0);printf("\n");
                continue;
        }
        if(judge(1,1))
        {

            for(int i=0;i<n;i++)
                if(a[i]==1)
                printf("%c",s1);
                else printf("%c",s0);printf("\n");
                continue;
        }
        if(judge(0,0))
        {

            for(int i=0;i<n;i++)
                if(a[i]==1)
                printf("%c",s1);
                else printf("%c",s0);printf("\n");
                continue;
        }
        if(judge(0,1))
        {

            for(int i=0;i<n;i++)
                if(a[i]==1)
                printf("%c",s1);
                else printf("%c",s0);printf("\n");
                continue;
        }
        printf("-1\n");



    }
    return 0;
}
