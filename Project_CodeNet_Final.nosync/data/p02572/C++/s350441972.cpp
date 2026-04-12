#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll int,ll int>
#define PI 2*acos(0)
#define INF 1e8
#define mx 1000006
using namespace std;
const ll int p=1000000007;
//vector<ll > prime;
//bool mark[mx];
ll int mod(ll int a,ll int b)
{
    ll int m=a%b;
    if(m<0) m=(b<0)?(m-b):(m+b);
    return m;
}
ll maxpow(ll n)
{
    return (n & (~(n-1)));
}
bool isPrime(ll n)
{
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3;i*i<=n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}
/*void init()
{
    mark[1]=1;
    int i,j,limit=sqrt(mx*1.0)+2;
    prime.push_back(2);
    for(i=4;i<mx;i+=2) mark[i]=1;
    mark[2]=0;
    for(i=3;i<mx;i+=2){
        if(!mark[i]){
            prime.push_back(i);
            if(i<=limit){
                for(j=i*i;j<mx;j+=2*i){
                    mark[j]=1;
                }
            }
        }
    }
}
/*
ll maxdiv(ll n)
{
    ll i,ans=1;
    for(i=0;i<prime.size();i++){
        if(n%prime[i]==0){
            ans=n/prime[i];break;
            //return ans;
        }
    }
    return ans;
}*/
ll lcm(ll a,ll b)
{
    ll ans=a*b;
    return (ans/__gcd(a,b));
}
// ax+by and a>b
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=gcd(b,mod(a,b),x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
ll abso(ll a)
{
    if(a>=0) return a;
    return -a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i,j,k,mul,sum,cnt,ans;
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++) cin>>a[i];
    ll s[n+1];s[0]=0;
    s[1]=a[1];
    for(i=2;i<=n;i++) s[i]=mod(s[i-1]+a[i],p);
    sum=0;
    for(i=1;i<=n;i++){
        sum+=mod(a[i],p)*mod(s[n]-s[i],p);
        sum=mod(sum,p);
    }
    cout<<sum;
    return 0;
}
//1028C
