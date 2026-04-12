#include<bits/stdc++.h>
#define up(j,k,i) for(i=j;i<k;i++)
#define down(j,k,i) for(i=j;i>k;i--)
#define pp(n) printf("%lld\n",n)
#define ps(s) printf("%s",s)
#define is(n) scanf("%lld",&n)
#define ips(n) scanf("%lld",n)
#define ss(s) scanf("%s",s)
#define cool 0
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f(i) cout<<i<<endl;
#define pll pair<lld,lld> 
#define pi acos(-1)
#ifdef G
#define dg(x) cout<<#x<<' '<<x<<endl;
#define dg2(x,y) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<endl;
#define dg3(x,y,z) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<endl;
#define dg4(x,y,z,zz) cout<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<' '<<#zz<<' '<<zz<<endl;
#else
#define dg(x) ;
#define dg2(x,y) ;
#define dg3(x,y,z) ;
#define dg4(x,y,z,zz) ;
#endif
#define ds(n,m) scanf("%lld %lld",&n,&m)
#define ts(n,m,k) scanf("%lld %lld %lld",&n,&m,&k)
#define yes printf("YES\n")
#define no printf("NO\n")
typedef long double ld;
typedef long long int lld;
using namespace std;
const lld M =1e18+7;
const lld mod=1e9+7;
const lld infi =LLONG_MAX;
lld ans,k,n,x,y,m,mymax=LLONG_MIN,mymin=LLONG_MAX,b,c,z,sum;
int main()
{
      lld i,j;
        ts(x,y,z);
        ans=100*x+10*y+z;
        if(ans%4==0)
        {
          yes;
        }
        else
        {
          no;
        }
        return 0;
}