#include<bits/stdc++.h>
/******* MY EVERY AC WILL BE A TRIBUTE TO SSR ********/
#define vi vector
#define lli long long int
#define vli vi<lli>
#define pb push_back
#define pll pair<lli,lli>
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(),greater<lli>()
#define clear(x) x.clear()
#define rep(i,n) for(lli i=0;i<(lli)n;i++)
#define rep1(i,n) for(lli i=1;i<=(lli)n;i++)
#define rep2(i,n) for(lli i=1;i<(lli)n;i++)
#define refor(i,n) for(lli i=(lli)n;i>=0;i--)
#define range(i,l,r) for(lli i=(lli)l;i<=(lli)r;i++)
#define big(x,y) (x>y)?x:y
#define small(x,y) (x<y)?x:y
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mod 1000000007
using namespace std;
lli gcd(lli a,lli b) {return b==0?a:gcd(b,a%b);}
lli lcm(lli a,lli b) {return (a*b)/gcd(a,b);}
bool isprime(lli x) {for(lli i=2;i<=sqrt(x);i++) { if(x%i == 0) return false;} return true;}
lli modpow(lli x,lli y) {x%=mod;lli res=1;while(y>0){if(y&1) res*=x%mod; y=y>>1; x=x*x%mod;} return res%mod;}
lli ncr(lli n,lli k) {lli res=1; if(k>n-k) k=n-k; rep(i,k){res*=(n-i);res/=(i + 1);} return res;}
lli bintodec(lli n) {lli decimal=0,i=0,rem;while (n!=0){rem = n%10;n/=10;decimal += rem*pow(2,i);++i;}return decimal;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
     
     lli x;
     cin>>x;
     if(x>=30)
      cout<<"Yes\n";
      else
      cout<<"No\n";

    return 0;
}









