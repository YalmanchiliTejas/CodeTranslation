
 #include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<bitset>
#define lson node<<1,st,mid
#define rson node<<1|1,mid+1,ed
#define mem(a,x) memset(a,x,sizeof(a))
#define me(a) memset(a,0,sizeof(a))
#define IOS ios::sync_with_stdio(false)
#define lowbit(x) x&(-x)
#define up(i,x,y) for(long long i=x;i<y;i++)
#define down(i,x,y) for(long long i=x;i>=y;i--)
#define in freopen("in.txt","r",stdin)
#define out freopen("out.txt","w",stdout)   
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f;
const ll maxn = 1e6 + 5;
const ll N=1e3+5;
const double pi = acos(-1.0);
const double eps=1e-9;
using namespace std;


ll a[maxn];
ll b[maxn];
int main(){
   // in;
   // out;
   IOS;
   ll n;
   cin>>n;
   for(ll i=1;i<=n;i++){
      cin>>a[i];
   }
   ll sum=0;
   for(ll i=2;i<=n;i++){
      sum=(sum+a[i])%mod;
   }
   // cout<<sum<<endl;
   b[1]=sum;
   for(ll i=2;i<=n;i++){
      sum-=a[i];
      if(sum<0) sum+=mod;
      b[i]=sum;
   }

   ll ans=0;
   for(ll i=1;i<n;i++){
      ans=(ans+(a[i]*b[i])%mod)%mod;
   }
   cout<<ans<<endl;

}