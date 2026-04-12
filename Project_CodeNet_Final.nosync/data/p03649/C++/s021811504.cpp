#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;
cin>>n;
vector<ll> a(n),b(n,0);
for(int i=0;i<n;i++)cin>>a[i];
ll tmp=1,ans=0,bfo=0;
bool ok=true;
while(ok){
    ok=false;
    ll cnt=0,tmp=0,t;
   for(int i=0;i<n;i++){
          cnt+=(a[i]+bfo-b[i])/n;
          t=(a[i]+bfo-b[i])/n;
          a[i]=(a[i]+bfo-b[i])%n;
          b[i]=t;
   }
   ans+=cnt;
   bfo=cnt;
   for(int i=0;i<n;i++){
       if((a[i]+bfo-b[i])>=n)ok=true;
   }
}
cout<<ans<<endl;
}