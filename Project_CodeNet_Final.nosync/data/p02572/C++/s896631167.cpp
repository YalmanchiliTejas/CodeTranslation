#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define scan(n) scanf("%d",&n)
#define ls(n) scanf("%lld",&n)
#define print(n) printf("%d",n)
#define pln(n) printf("%d\n",n)
#define lpln(n) printf("%lld\n",n)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define rev(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define tc           ll t1; cin>>t1; while(t1--)
#define inp         ll n; cin>>n; ll arr[n]; rep(i,0,n) cin>>arr[i];
#define vect vector<ll>
#define sortv(v)       sort(v.begin(),v.end())
#define lower(v,n)    lower_bound(v.begin(),v.end(),n)-v.begin()
#define upper(v,n)    upper_bound(v.begin(),v.end(),n)-v.begin()
#define all(v)        v.begin(),v.end()
#define bitcount(n) __builtin_popcount(n)
#define ln <<endl
#define inf          1e12+5
#define ninf         -1e17
#define fast()         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const   ll mod=1e9+7;
const ll N=1e5+5;



int main() 
{ 
          fast();
         

          int n;
          cin >> n;
          std::vector<ll> a(n);
          rep(i,0,n)
          cin >> a[i];
          std::vector<ll> sum(n);
          sum[n-1]=a[n-1];
          for(int i=n-2;i>=0;i--)
          sum[i]=(sum[i+1]+a[i])%mod;
        ll ans=0;
        // rep(i,0,n)
        // cout<<sum[i]<<" ";
        // cout<<endl;
        rep(i,0,n-1)
        {
          ans=(ans+sum[i+1]*a[i])%mod;
        }
        cout<<ans;

          
           return 0; 

} 