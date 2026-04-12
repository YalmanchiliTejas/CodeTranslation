#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

 
 
const ll N = 100005;
const ll mod = 1000000007;
const long long int inf = 1e10+5;
#define pp pair<ll,ll>
 
typedef long double ld;
typedef vector<pp> vpl;
#define MP make_pair
#define endl "\n"
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n;i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define repb(i,n) for(ll i=1;i<n-1;i++) 
#define trace(i,a) for(auto i=a.begin();i!=a.end();i++) 
#define mtrace(i,a) for(auto i=a.begin();i!=a.end();i++)  cout<<i->first<<" "<<i->second<<endl;   




void fastIO(void);
void decimal(int);
ll modmulti(ll, ll);
ll modadd(ll, ll);
ll modpower(ll, ll);
ll gcd(ll, ll );
ll modinv(ll);




int main(){
    
     
   ll a,b;
   cin>>a>>b;
   if(a==b) cout<<"Yes\n";
   else cout<<"No\n";






   

}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
void fastIO(void)
{  ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
}
 
void decimal(int n){
   cout<<fixed;
   cout<<setprecision(n);
}
ll modmulti(ll a, ll b){
   return ((a%mod)*1ll*(b%mod))%mod;
}
ll modadd(ll a, ll b){
   ll asdfgh =  ((a%mod)+(b%mod)+mod+mod)%mod;
   asdfgh = (asdfgh+mod)%mod;
   return asdfgh;
}
ll modpower(ll a, ll n){
   if(n==0) return 1;
   if(n==1) return a%mod;
   ll b = modpower(a,n/2);
   b = modmulti(b,b);
   if(n%2==0) return b;
   return modmulti(a,b);
}
ll gcd(ll a, ll b){
   if(b==0)
      return a;
   return gcd(b,a%b);
}
ll modinv(ll a){
   return modpower(a,mod-2);
}
 