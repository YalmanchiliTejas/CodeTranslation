#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forp(i,a,b) for (int i = (a); i <(b); i++)
#define forn(i,a,b) for (int i = (a); i >(b); i--)
#define mod 1000000007
#define multiple_testcases_t int t;cin>>t;while(t--){solve();}
#define single_testcase_t solve();
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;


long long int multiply(long long int a,long long int b) 
{ 
    long long int res = 0,f=0,p=0; 
    a =(a+mod)%mod;
    if(b<0)
     f=1;
     b=abs(b);
    while (b) 
    {
        if (b & 1) 
            res = (res + a) % mod;
        a = (2 * a) % mod; 
        b >>= 1;
    } 
    if(f)
    res*=(-1);
    return res; 
}

// <----- Actual solve() function to print output -----> //
int tc=1;
void solve()
{
   ll n,k=0,z=-1,ans=0;
cin>>n;
ll a[n];
ll p[n];
forp(i,0,n)
{
   cin>>a[i];

   if(i==0)
   p[i]=a[i];
   else
   {
      p[i]=p[i-1]+a[i];
   }
}
ans=0;
forp(i,0,n)
{
   k=multiply(a[i],(p[n-1]-p[i]))%mod;
   ans=ans%mod+k%mod;
}
  cout<<ans%mod;
 //  cout<<"\n";      //if t>1 uncomment this
}

// MAIN function --------------------------------------------------------------------------//
int main()
{
    fast_io
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  single_testcase_t
 // multiple_testcases_t
return 0;
}



