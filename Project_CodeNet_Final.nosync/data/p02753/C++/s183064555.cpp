#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define all(v)  v.begin(),v.end()
#define pb push_back
#define size(v)  (int) v.size()
#define fast ios_base:: sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
ll power_mod(ll a,ll x){if(x==0) return 1;ll y=power_mod(a,x/2);ll ans=(y*y)%mod; if(x%2) ans=(ans*a)%mod;return ans;}
ll inv(ll a){return power_mod(a,mod-2);}    
#define N 100005


int main(){
    
    string s;
    cin>>s;

    int a=0,b=0;
    for(int i=0;i<3;i++)
    {
    	if(s[i]=='A') a++;
    	else b++;
    }
    if(a==3 or b==3)
    {
    	 cout<<"No"<<endl;
    }
    else
    {
    	 cout<<"Yes"<<endl;
    }


}