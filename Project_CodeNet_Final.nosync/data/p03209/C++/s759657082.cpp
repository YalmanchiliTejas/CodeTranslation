#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define N 55
ll s[N],c[N];
ll f(ll n,ll x){
    if(n==0)return 0;
    if(x==0)return 0;
    else if(x==1)return 1;
    else if(x<=1+s[n-1])return 1+f(n-1,x-1);
    else if(x==2+s[n-1])return 1+c[n-1];
    else if(x<=2+2*s[n-1])return 1+c[n-1]+f(n-1,x-(2+s[n-1]));
    else return c[n];
}
int main(){
    s[0]=1;
    lol(i,N-1)s[i+1]=s[i]*2+3;
    c[0]=0;
    lol(i,N-1)c[i+1]=c[i]*2+2;
    ll n,x;cin>>n>>x;
    cout<<x-f(n,x)<<endl;
    return 0;
}
