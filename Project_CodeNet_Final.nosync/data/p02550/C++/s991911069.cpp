/* ****mittal21**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define endl        '\n'
#define pii         pair<long long int,long long int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
#define N  100005
ll pre[N],pr[N];
void solve()
{
   ll n,x,m;
   cin>>n>>x>>m;
   pre[1]=x;
   ll sum=x;
   for(int i=2;i<=min(n,100001LL);i++)
   {
      pre[i]=(pre[i-1]*pre[i-1])%m;
      sum+=pre[i];

   }
   if(n<=100001)
   {
      ll ans=0;
      for(int i=1;i<=n;i++)
        ans+=pre[i];
      cout<<ans;
      return;
   }
   ll cnt=100001;
   for(int i=100000;i>=1;i--)
   {
       if(pre[i]==pre[100001])
       {
         cnt=i;
         break;
       }
   }
   ll op=100001-cnt;
   for(int i=cnt+1;i<=100001;i++)
    pr[i-cnt]=pre[i]+pr[i-1-cnt];
   ll ans=sum;
   ll rem=n-100001;
   ans+=(rem/op)*pr[op];
   ans+=pr[rem%op];
   cout<<ans;



   return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcase=1;
    //cin>>testcase;
    while(testcase--)
    {
        solve();
    }
    return 0;
}