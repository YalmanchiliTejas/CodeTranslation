#include <bits/stdc++.h>
 
using namespace std;
 
template< class t>
long long int gcd( t g,t h )
{
    return ( h==0 ? g : gcd(h,g%h) );
}
 

struct Comp {
  bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second > b.second;
  }

}comp_functor;
 
 
int main() 
{
    ios_base::sync_with_stdio(false) ; cin.tie(0) ;
    
    long long int i,j,ans=0,c,a[300005],n,f=0;
    
    string s;
    
    cin>>s;
    
    n=s.length();
    
    if(n==1)
    {
        cout<<"No";
    }
    
    for(i=1;i<n;i++)
    {
        if(s[i-1]=='A'&&s[i]=='C')
        {
            f=1;
        }
    }
    
    
    if(f==1)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    
    return 0;
}
 