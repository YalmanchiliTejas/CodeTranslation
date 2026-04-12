#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mod 1000000007
#define modd 998244353
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define ar array
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
lld n,m;
lld arr[300000];
lld brr[300000];
lld sol(){
    sort(arr,arr+n,greater<lld>());
    lld ret=0;
    rep(i,0,n-1)brr[i]=0;
    rep(i,0,n-1){
        ret+=arr[i]/n;
        brr[i]=arr[i]/n;
    }
    rep(i,0,n-1)arr[i]=arr[i]%n+ret-brr[i];
    return ret;
}
int main()
{
     ios;
     lld TESTS,q,a,s,b,l,r,c,k,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
     //memset(brr,-1,sizeof(brr));
     //cin>>TESTS;
     while(TESTS--)
     {
         cin>>n;
         rep(i,0,n-1)cin>>arr[i];
         lld ans=0;
         lld x=sol();
         while(x){
            ans+=x;
            x=sol();
         }
         cout<<ans<<"\n";
     }
    return 0;
}
