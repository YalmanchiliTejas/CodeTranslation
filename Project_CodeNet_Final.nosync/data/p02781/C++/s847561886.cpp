#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
const int MX=4e5+7;
const int mod=9901;
using namespace std;
int p[MX],k[MX];
ll qpow(ll a,ll b,ll MOD=mod){for(ll ans=1;;a=a*a%MOD,b>>=1){if(b&1)ans=ans*a%MOD;if(!b)return ans;}}
ll inv(ll a,ll MOD=mod){return qpow(a,MOD-2,MOD);}
ll __gcm(ll a,ll b){return a*b/__gcd(a,b);}
map<string,int>mp;
int a[MX];
ll __C(ll n,ll m)
{
    if(n<m)return 0;

    if(m==1)return 9*n;
    else {
        return 9*9*n*(n-1)/2;
    }
}
int __get(int n,int m,int k)
{
    //if(m==0)m=1;
    if(k==0)return m;
    return m*__C(n,k);
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0);
  string s;
  int k;
  cin>>s>>k;
  int g=k;
  ll sum=0;
  ll res=0;
  int n=s.length();
  if(res==k)sum++;
  for(int i=0;i<n-1;i++)
   {
       sum+=__get(i,9,k-1);
     //cout<<sum<<endl;
   }
   //cout<<sum<<endl;
  // cout<<sum<<endl;
  for(int i=0;i<n;i++)
  {
      if(k){
       // if(i>0)s[i]++;
       if(s[i]-'0'>0)
        sum+=__get(n-i-1,s[i]-'0'-1,k-1);
       // cout<<sum<<endl;
        if(i>0&&s[i]-'0'>0)
        {
            sum+=__get(n-i-1,1,k);
          //  cout<<"i="<<i<<" "<<sum<<endl;
         // cout<<n-i-1<<" "<<s[i]-'0'-1<<" "<<k-1<<endl;
        }
       // cout<<sum<<endl;
       if(s[i]-'0'>0)k--;
      }
  }
  //cout<<sum<<endl;
  int ant=0;
  for(int i=0;i<n;i++)
  {
      if(s[i]-'0'>0)ant++;
  }
  //cout<<ant<<" "<<k<<endl;
  if(ant>=g)sum++;
  cout<<sum<<endl;
}
