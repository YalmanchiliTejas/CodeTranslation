#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define fi first
#define se second
#define pb push_back
#define soo(v) sort(v.rbegin(),v.rend())
#define so(v) sort(v.begin(),v.end())
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
//#define endl '\n'
#define dbv(v) cout<<endl;cout<<#v<<"-->> ";for(auto it:v){cout<<it<<" ";}cout<<endl;
#define dbm(m)cout<<endl;cout<<#m<<"-->> ";for(auto it:m){cout<<it.fi<<" "<<it.se<<endl;}
#define dbs(s)cout<<endl;cout<<#s<<"-->> ";for(auto it:s){cout<<it<<" ";}cout<<endl;
#define mod 1000000007
#define db1(x) cout<<#x<<"="<<x<<endl;
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl;
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl;
#define mx 1e18
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define double long double
#define io std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

int32_t main()
{
    io
 int n;cin>>n;
 vector<int>a(n);int sum=0;int tt=0;
for(int i=0;i<n;i++)cin>>a[i];vector<int>suff(n,0);
  for(int i=n-1;i>=0;i--)
  {
    if(i==n-1)
    {
      suff[i]=a[i];
    }
    else
    {
      suff[i]=(suff[i+1]%mod+a[i]%mod)%mod;
    }
  }
  int ans=0;
  for(int i=0;i<n-1;i++)
  {
      ans+=(a[i]%mod*suff[i+1]%mod)%mod;
      ans%=mod;
  }
  cout<<ans<<endl;


    
}