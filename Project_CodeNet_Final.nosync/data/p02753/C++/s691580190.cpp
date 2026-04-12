//Catchharsh
#include<bits/stdc++.h>
#define ll long long int 
#define ld long double
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
#define see(x) cout<<#x<<" = "<<x<<endl
const ll MOD = 1e9+7;
const ll INF = 1011111111;
const ll LLINF = 1000111000111000111LL;
const ld EPS = 1e-10;
const ld PI = 3.14159265358979323;
using namespace std;
ll power (ll base,ll exponent)
{
    ll ans=1;
    //base%=MOD;
    //exponent%=(MOD-1);
    while(exponent!=0)
    {
      if(exponent&1) ans=(1LL*ans*base);
      base=(1LL*base*base);
      exponent>>=1;
    }
    return ans;
}

int32_t main()
{   
     IOS;
     
     string s;
     bool A=false;
     bool B=false;
     cin>>s;
     for(ll i=0;i<(ll)s.length();i++)
     {
      if(s[i]=='A') A=true;
      else B=true;
     }
     if(A&B) cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
     
     cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';             
}