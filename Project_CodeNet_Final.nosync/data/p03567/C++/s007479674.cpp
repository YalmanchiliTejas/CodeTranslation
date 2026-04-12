#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define vl vector<long long>

#define vi vector<int> 
#define vii vector< vector<int> >
#define vll vector< vector<long long> >
#define vpi vector< pair<int,int> >   
#define vpl vector< pair<ll,ll> >   
#define viii vector< vector<vector<int> > >
typedef pair<pair<int, int>,int> P;
#define mod %1000000007
#define ld long double
bool less_vectors(const vector<int>& a,const vector<int>& b) 
{
  return a.size() > b.size();
}
class dc
{
    public:
bool operator()(pair<int,ll> p1,pair<int,ll>  p2)
{
    return p1.ss>p2.ss;
}

};
class comp
{
    public:
bool operator()(pair<int,pair<ll,ll> > p1,pair<int,pair<ll,ll> > p2)
{
    if(p1.ss.ff!=p2.ss.ff)
     return p1.ss.ff>p2.ss.ff;
     else
          return p1.ss.ss>p2.ss.ss;
}

};
int gcd(int a,int b)
{
if(a%b==0)
     return b;
     else
          return gcd(b,a%b);
}
ll fastexpo(ll a,ll b)
{
  
      ll res=1;
      while(b>0)
      {
        if(b%2==1)
          res=((res)mod*(a)mod)mod;
        a=((a)mod*(a)mod)mod;
        b/=2;
      }
      return res;
}
ll fastexpom(ll a,ll b,ll m)
{
  ll res=1;
      while(b>0)
      {
        if(b%2==1)
          res=(((res)%m)*((a)%m))%m;
        a=(((a)%m)*((a)%m))%m;
        b/=2;
      }
      return res;
}
ll modinv(ll a, ll m=1000000007)
{
  return fastexpom(a,m-2,m);
}
bool comparator(pair<int,int> p1,pair<int,int> p2)
{
  if(p1.ff!=p2.ff)
  {
    return p1.ff<p2.ff;
  }
  else
    return p1.ss<p2.ss;
}
int main()
{
     IOS;
    /* #ifndef ONLINE_JUDGE
     freopen("int.txt","r",stdin);
     freopen("out.txt","w",stdout);
     #endif*/
     string s;
     cin>>s;
     bool ch=0;
     for(int i=1;i<s.length();i++)
     {
        if(s[i-1]=='A' && s[i]=='C')
          ch=1;
     }
     if(ch)
      cout<<"Yes";
    else
      cout<<"No";
    


     return 0;
} 