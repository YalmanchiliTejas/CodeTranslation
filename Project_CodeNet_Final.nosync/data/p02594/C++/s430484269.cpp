#include <bits/stdc++.h>  
using namespace std;  
// Important header files   
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;  
  
// Declaring ordered_set 
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set; 
#define rep(i,n) for(li i=0;i<n;i++)
#define li long long int
#define ll long long int
#define pb push_back
#define all(v) sort(v.begin(),v.end())
const int N = 40043;
const ll mod = 1e9 + 7;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f first
#define s2 second
const ll INF=(1LL<<60)-1;


li gcd(li a,li b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
li lcm(li a,li b)
{
    return (a*b)/gcd(a,b);
}
li power(li a,li b)
{
    li res=1;
    while(b)
    {
        if(b&1)
        res=(res*a);
        a=((a)*(a));
        b>>=1;
    }
    return res;
}
 
li xx,yy,dd;
void equation(li a,li b)
{
    if(b==0)
    {
        xx=1;
        yy=0;
        dd=a;
    }
    else
    {
        equation(b,a%b);
        li temp=xx;
        xx=yy;
        yy=temp-(a/b)*yy;
    }
}
li inverse(li a,li m)
{
    equation(a,m);
    return(xx%m+m)%m;
}
bool compare(const pair<li,li> &i, pair<li,li> &j)
{
    if(i.f==j.f)
    return i.s2 > j.s2;
    else
    return i.f<j.f;
    
}


void solve()
{
    int x;
  cin>>x;
  if(x>=30)
  cout<<"Yes";
  else
  cout<<"No";
}
signed main()
{
   //seive();
   //cout<<prime.size();
   FAST_IO;
   int t;
   t=1;
   while(t--)
   {
       solve();
       cout<<endl;
      
   }
}