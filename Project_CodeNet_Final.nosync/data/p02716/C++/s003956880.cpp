#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define big 998244353
#define ff first
#define se second
#define pb push_back
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PSET(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define pi 3.141592653589
int power(int x,int y){
    int r=1,z=x;
    while(y){
        if(y & 1)r*=z;
        z*=z;y=y>>1;}
    return r;}
int powerm(int x,int y,int p){
    int r=1;
    while(y){
        if(y & 1)r=(r*x)%p;
        y=y>>1;
        x=(x*x)%p;}
    return r%p;}
int modinv(int x,int m){
    return powerm(x,m-2,m);}
int logarithm(int a,int b){
    int x=0;
    while(a>1){
        x++;
        a/=b;}
    return x;}
int32_t main(){
    fast;
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n%2){
        int ans=0;
        for(int i=1;i<=n-2;i+=2)
            ans+=a[i];
        int sum[n+1];
        sum[n]=a[n];
        for(int i=n-2;i>=1;i-=2)
            sum[i]=sum[i+2]+a[i];
        sum[n-1]=a[n-1];
        for(int i=n-3;i>=1;i-=2)
            sum[i]=max(sum[i+2],sum[i+3])+a[i];
        int curr=0;
        int i;
        for(i=3;i<=n;i+=2)
        {
            ans=max(ans,max(sum[i],sum[i-1])+curr);
            curr+=a[i-2];
        }
        cout<<ans;
    }
    else{
        int sum[n+1];
        int ans=0;
        sum[n]=a[n];
        for(int i=n-2;i>=1;i-=2)
            sum[i]=sum[i+2]+a[i];
        sum[n-1]=a[n-1];
        for(int i=n-3;i>=1;i-=2)
            sum[i]=max(sum[i+2],sum[i+3])+a[i];
        ans=max(sum[1],sum[2]);
        cout<<ans;
    }
    return 0;
}