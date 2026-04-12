#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define dd double
#define pb push_back
#define ff first
#define ss second
#define Mp make_pair
const ll Mod=1000000007;
const ll INF=999999999999999999;
const ll NN=(ll)(1e6+5);
ll min(ll x,ll y){if(x<y) return x;return y;}
ll max(ll x,ll y){if(x>y) return x;return y;}
ll power(ll x,unsigned ll y) 
{ 
    if (y==0) 
        return 1; 
    else if (y%2==0) 
        return power(x,y/2)*power(x,y/2); 
    else
        return x*power(x,y/2)*power(x,y/2); 
}
ll hcf(ll a,ll b) 
{ 
    if(b==0) 
        return a; 
    return hcf(b,a%b);  
}
int main()
{
   fio;
   /*#ifndef ONLINE_JUDGE 
    	freopen("input.txt", "r", stdin); 
    	freopen("output.txt", "w", stdout); 
    	freopen("error.txt", "w", stderr); 
   #endif*/
   ll TT=1;
   //cin>>TT;
   while(TT--)
   {
     ll x;
     cin>>x;
     cout<<(x>=30?"Yes":"No");
   }
}