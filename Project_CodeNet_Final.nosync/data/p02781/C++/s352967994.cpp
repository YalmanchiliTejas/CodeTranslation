#include<bits/stdc++.h>
#define rep(i,k,n)     for (ll i = k; i < n; ++i)
#define repr(i,k,n)    for (ll i = k; i >= n; --i)
#define repp(p,a)      for (p=a.begin();p!=a.end();++p)
#define all(a)         a.begin(),a.end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define reppn(p,a,n)    for (p=a.begin();(p+n)!=a.end();++p)
#define F              first
#define S              second
#define ll             long long
#define hell           1000000007
#define god            LLONG_MAX
#define lb             lower_bound
#define ub             upper_bound
#define pb             push_back
#define ct             continue
#define endl           '\n'
#define sp(n)          setprecision(n)
#define srt(a)         sort(all(a))
#define srtd(a)        sort(a.rbegin(),a.rend())
#define sz(a)          ll((a).size())
#define sum(a)         accumulate(all(a),(ll) 0)
#define pdt(a)         accumulate(all(a),double(1),multiplies<double> ())
#define dotpdt(a,b)    inner_product(all(a),b.begin(),0)
#define mkp(a,b)       make_pair(a,b)
#define REP(x,s)       for (auto x : s)
using namespace std;

ll dp3(ll n)
{
    return 121.5*(n)*(n-1)*(n-2);
}
ll dp2(ll n)
{
    return 40.5*(n)*(n-1);
}
ll dp1(ll n)
{
    return 9*n;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t=1;
  //cin>>t;
  while(t--)
  {
      string sp,s="";
      ll k;
      cin>>sp>>k;
      ll n=sp.size(),k1,k2,k3,c=0,z=0,b=0,flag1=1,flag2=1,flag3=1;
      rep(i,0,n)
      {
          if(sp[i]!='0')
          {
              z++;
          }
      }
      //cout<<z<<endl;
      if(n==3 && k==3)
      {
          ll x=sp[0]-'0';
          ll y=sp[1]-'0';
          ll z=sp[2]-'0';
          ll a=x*100+y*10+z;
          if(a<111)
          {
              cout<<0;
              return 0;
          }
      }
      if(k==3)
      {
          if(z==1)
          {
              if(sp.size()>=4)
              {
                  s+=to_string(((sp[0]-'0')-1));
                  rep(i,0,sp.size()-1)
                  {
                      s+='9';
                      flag1=0;
                  }
              }
              else
              {
                  cout<<0;
                  return 0;
              }
          }
          else if (z==2)
          {
              flag2=0;
              repr(i,n-1,0)
              {
                  if(sp[i]!='0')
                  {
                      b=i;
                      break;
                  }
              }
              //cout<<b<<endl;
              if(b>=(n-2))
              {
                  s+=to_string(((sp[0]-'0')-1));
                  rep(i,0,sp.size()-1)
                  {
                      s+='9';
                  }
              }
              else
              {
                  //cout<<"hi"<<endl;
                  rep(i,0,b)
                  {
                      s+=sp[i];
                  }
                  s+=to_string(((sp[b]-'0')-1));
                  rep(i,b,sp.size()-1)
                  {
                      s+='9';
                  }
              }
          }
      }
      else if(k==2)
      {
          if(z==1)
          {
              flag3=0;
              if(sp.size()>=3)
              {
                  s+=to_string(((sp[0]-'0')-1));
                  rep(i,0,sp.size()-1)
                  {
                      s+='9';
                  }
              }
              else
              {
                  cout<<0;
                  return 0;
              }
          }
      }
      if(flag1*flag2*flag3)
      {
          rep(i,0,n)
          {
              s+=sp[i];
          }
      }
      //cout<<s<<endl;
      rep(i,0,n)
      {
          if(s[i]!='0')
          {
              c++;
              if(c==1)
              {
                  k1=i;
              }
              else if(c==2)
              {
                  k2=i;
              }
              else if(c==3)
              {
                  k3=i;
              }
          }
      }
      
      if(k==3)
      {
          ll n1=n-k1,n2=n-k2,n3=n-k3;
          cout<<dp3(n1-1)+(dp2(n1-1)*((s[k1]-'0')-1))+dp2(n2-1)+(dp1(n2-1)*((s[k2]-'0')-1))+( (s[k3]-'0')*n3+(9-(s[k3]-'0'))*(n3-1));
      }
      else if(k==2)
      {
          ll n1=n-k1,n2=n-k2;
          cout<<dp2(n1-1)+dp1(n1-1)*((s[k1]-'0')-1)+(s[k2]-'0')*n2+(9-(s[k2]-'0'))*(n2-1);
      }
      else
      {
          ll n1=n-k1;
          cout<<(s[k1]-'0')*n1+(9-(s[k1]-'0'))*(n1-1);
      }
  }      
 
 
 return 0;
}