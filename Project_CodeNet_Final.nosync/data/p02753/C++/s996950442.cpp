#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define Mod 1000000007
#define ll long long
#define dd double
#define pb push_back
#define ff first
#define ss second
#define Mp make_pair
#define INF (ll)(1e17+5)
#define NN (ll)(1e6+5)
int mod(string s,int a) 
{ 
    int ans=0; 
    for (int i=0;i<s.length();i++) 
         ans=(ans*10+(int)s[i]-'0')%a; 
    return ans; 
}
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
       string s;
       cin>>s;
       ll i,a=0,b=0;
       for(i=0;i<s.length();i++)
       {
           if(s[i]=='A')
            a++;
           else
            b++; 
       }      
       if(a&&b)
        cout<<"Yes\n";
       else
        cout<<"No\n"; 
   }
}