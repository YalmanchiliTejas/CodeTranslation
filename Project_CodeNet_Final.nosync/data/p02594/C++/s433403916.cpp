#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ms memset
#define MOD 1000000007
#define sp fixed<<setprecision
#define sz sizeof
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod2=998244353;
ll fpow(ll x,ll y,ll p=MOD){x=x%p;ll sum=1;while(y){if(y&1)sum=sum*x;sum%=p;y=y>>1;x=x*x;x%=p;}return sum;}
ll inv(ll a,ll m=MOD){ll c=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=c;return x;}
ll spf[10005];
void sieve()
{
  for(int i=1;i<10005;i++)
  spf[i]=i;
  for(int i=2;i*i<=10005;i++)
  if(spf[i]==i)
  for(int j=2*i;j<10005;j+=i)
  spf[j]=min(spf[j],(ll)(i));
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   ll x;
   cin>>x;
   if(x>=30)
   cout<<"Yes\n";
   else
   cout<<"No\n";

}
