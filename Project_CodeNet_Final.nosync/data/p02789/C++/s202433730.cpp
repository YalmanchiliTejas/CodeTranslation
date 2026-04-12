#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define print(A,n) for(ll i=0;i<n;++i)cout<<A[i]<<' ';cout<<endl;
#define take(A,n) for(ll i=0;i<n;++i)cin>>A[i];
ll mulmod(ll a,ll b,ll c) 
{ 
    if (b==0) 
        return 0; 
    ll s = mulmod(a, b/2, c); 
    if (b%2==1) 
        return (a%c+2*(s%c)) % c; 
 
    else
        return (2*(s%c)) % c; 
} 
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
ll int t;
t=1;

while(t--)
{ ll int n,m,i,j,k,count=0,flag=0;
cin>>n>>m;
if(n==m)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;


    
    
    
    
    
    
    
    
}



 
    return 0;
}