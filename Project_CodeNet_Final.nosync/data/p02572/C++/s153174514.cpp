#include<bits/stdc++.h>
using namespace std;
/*
    By: Umang Srivastava
*/
#define lli long long int
#define ld long double
#define mod 1000000007
#define lp(var,start,end,inc) for (var = start; var <end ; var=var+inc)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<lli>
#define pll pair<lli,lli> 
#define vpll vector<plli>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b


// lli findgcd(lli a, lli b, lli *x , lli *y)
// {
//     if(a==0)
//     {
//         *x=0,*y=1;
//         return b;
//     }
//     lli x1,y1;
//     lli gcd = findgcd(b%a,a,&x1,&y1);
//     *x=y1-(b/a)*x1;
//     *y=x1;
//     return gcd;
// }

// lli modInv(lli b)
// {
//     lli x,y;
//     lli g = findgcd(b,mod,&x,&y);
//     if(g!=1)
//         return -1;
//     return (x%mod + mod)%mod;
// }

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,s=0,i,s2=0,ans;
    cin>>n;
    lli ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        s= (s + ar[i])%mod;
        s2 = (s2%mod + (ar[i]*ar[i])%mod)%mod;
    }
    s=((s%mod)*(s%mod))%mod;

    s=((s-s2)%mod+mod)%mod;
    lli inv = 500000004;

    ans=(s*inv)%mod;
    cout<<ans;

}