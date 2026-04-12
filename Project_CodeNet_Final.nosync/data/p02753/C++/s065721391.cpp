/*Author SHUBH AGRAWAL  */

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pu push  //  adds the value to the last of the queue 
#define lld long long int
#define ins insert /// used in set to insert the values 
#define adv advance  /// used to increment the iterator
#define mp make_pair
#define fi first
#define se second
#define all(c) c.begin(),c.end()
#define PI 3.1415926
//a power n mod p

#define vl  vector<long long int >
#define vpl vector< pair<lld ,lld> >
#define vvl vector<vector<lld> > 

long long int modp(lld a,lld p,lld n)
{
    int d[100];
    int i,j,k,l;
    if(n==0) return 1;
    for(i=0;n>=1;i++)
    {
        d[i]=n%2;
        n/=2;
    }
    l=i;
    long long int e=1;
    if(d[0]==1) e*=(a%p);
    for(i=1;i<l;i++)
    {
        a*=a;
        a=a%p;
        if(d[i]==1) 
        {
            e*=a;
            e=e%p;
        }
    }
    return e%p;
}
lld modInverse(lld n, lld p) 
{ 
    return modp(n, p, p-2); 
}

long long int nCrModPFermat(lld n, lld r,lld p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
    
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    lld fac[n+1]; 
    fac[0] = 1; 
    for (lld i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
}


long long int gcd(lld b,lld a)
{
    if(a<b) return gcd(a,b);
    if(a%b==0) return b;
    return gcd(a%b , b);
}


lld l,r,mid,ans;
lld n,m,i,j,k;
lld x,w,y,z;

void solve()
{
    string s;
    cin>>s;
    x=y=0;
    for(i=0;i<3;i++)
    {
        if(s[i]=='A') x+=1;
        else y+=1;
    }
    if(x*y) cout<<"Yes";
    else cout<<"No";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}