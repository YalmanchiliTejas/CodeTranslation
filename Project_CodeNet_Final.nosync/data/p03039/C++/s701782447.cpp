/*      Abhijith    */
#include<bits/stdc++.h>
#include<iomanip>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
using namespace std;
void gcd_extended(lld a,lld b,lld *x,lld *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return;
    }
    lld x1,y1;
    gcd_extended(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return;
}
lld ncr(lld n,lld k)
{
    if (k > n) return 0LL;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result = (result*(n-i+1))%mod;
    }
    for(int i=2;i<=k;i++)
    {
        lld x,y;
        gcd_extended(mod,i,&x,&y);
        y=(y%mod+mod)%mod;
        result=(result*y)%mod;
    }
    return result;
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     lld n,m,k;
     lld inv=500000004;
     cin>>n>>m>>k;
     vector<lld> vsum(n),vssum(n,0),hsum(m,0),hssum(m,0);
     vsum[0]=0;
     rep(i,1,n-1)
     {
         vsum[i]=(vsum[i-1]+1)%mod;
         vssum[i]=(vssum[i-1]+vsum[i])%mod;
     }

     hsum[0]=0;
     rep(i,1,m-1)
     {
         hsum[i]=(hsum[i-1]+1)%mod;
         hssum[i]=(hssum[i-1]+hsum[i])%mod;
     }
     lld haha=0;
     lld vava=0;
     rep(i,0,n-1)
     {
         vava=(vava+(vssum[i]+vssum[n-1-i]))%mod;
     }
     rep(i,0,m-1)
     {
         haha=(haha+(hssum[i]+hssum[m-1-i]))%mod;
     }
     lld yo=((n*(n))*haha+(m*(m))*vava)%mod;
     //cout<<haha<<" "<<vava<<" "<<yo<<endl;
     yo=(yo*inv)%mod;
     lld ans=(ncr(n*m-2,k-2)*yo)%mod;
     cout<<ans<<endl;
    return 0;
}
