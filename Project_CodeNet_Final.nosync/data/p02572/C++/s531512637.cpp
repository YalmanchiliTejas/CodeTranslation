#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define YUGEN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lp(i,start,end) for(int i=start;i<end;i++)
#define MAX 105
#define BPC(x)  __builtin_popcountll(x)
#define test() ll t; cin>>t; while(t--)
#define gcd(a,b)  __gcd(a,b)
#define SIZE 26
ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}

int main()
 {
    YUGEN;
      // test()
      // {
        // ll a,b;
       // cin>>a>>b;
       // ll ans=0;
        //if(a<b)
        //{
         //  int x=(b-a);
         //  if(x&1)
        //   ans++;
        //   else
        //   ans+=2;
       // }
      //   else if(a==b)
      //   ans=0;
      //   else if(a>b)
      //   {
      //     int x=(a-b);
      //     if(x&1)
      //     ans+=2;
      //     else
      //     ans++;
          
      //   }
      //   cout<<ans<<endl;
      // }
      ll n;
      cin>>n;
      ll a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];
      ll sum=0;
      for(int i=0;i<n;i++)
      {
        sum+=a[i];
        sum%=mod;
      }
      ll ans=0;
      for(int i=0;i<n;i++)
      {
        sum-=a[i];
        if(sum<0)
        sum+=mod;
        ans+=a[i]*sum;
        ans%=mod;
      }
      cout<<ans;
 }


