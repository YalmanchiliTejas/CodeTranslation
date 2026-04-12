#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n);
#define PI acos(-1.0)
#define sl(n) scanf("%lld",&n);
#define sf(n) scanf("%lf",&n);
#define ss(n) scanf("%s",n);
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define forc(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define pi(x)  prllf("%d",x);
#define pl(x)  prllf("%lld",x);
#define pf(x)  prllf("%.10lf",x);
#define ps(x)  prllf("%s",x);
#define en() prllf("\n");
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define SQR(a) (a)*(a)
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}

int prime[1000000];bool visprime[10000000];
void sieve(){int k=0;for(int i=2;i*i<=1000000;i++){for(int j=i*i;j<=1000000;j+=i){visprime[j]=true;}}for(int i=2;i<=1000000;i++){if(visprime[i]==false) prime[k++]=i;}}


int main()
{


  ll  a,b;
  cin>>a>>b;
  if(a==b) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;


















}
