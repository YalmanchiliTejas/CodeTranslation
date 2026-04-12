#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define maa 998244353
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=100000 ;
///Power
ll  power(ll  i,ll  j)
{
    if(j==0)
    return 1 ;
    ll t=power(i,j/2)%maa ;
    if(j%2==0)
    return (t%maa*t%maa)%maa ;
    else
    return ((t%maa*t%maa)%maa*(i%maa)%maa)%maa ;
}
int main()
{
   fast ;
  string s ;
  cin>>s ;
  ll a=0,b=0 ;
  for(ll i=0;i<3;i++)
  {
      if(s[i]=='A')
        a++ ;
      else
        b++ ;
  }
     if(a==3||a==0)
        cout<<"No"<<endl ;
     else
        cout<<"Yes"<<endl ;


}
