#include <bits/stdc++.h>
typedef long long unsigned int ll;
#define mod 1000000007
// #define mod 13
using namespace std;

int func(string s,string t,int i, int j){
    if(j<0){
        return 0;
    }
    else if(i<0){
        return j+1;
    }
    else if(t[j]==s[i]){
        return(func(s,t,i-1,j-1));
    }
    else{
        return (min(func(s,t,i-1,j-1)+1,func(s,t,i-1,j)));
    }
}
ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    return(gcd(b%a,a));
}
ll power(ll x,ll y){
    if(y==0){
        return 1;
    }
    ll p=power(x,y/2);
    p=(p*p)%mod;
    return (y&1)? (x*p)%mod : p;
}
ll modInverse(ll a){
    return (power(a,mod-2));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    scanf("%d",&n);
    ll a[n];
    for (int i=0;i<n;i++){
        scanf("%llu",&a[i]);
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum=(sum+a[i])%mod;
    }
    sum=(sum*sum)%mod;
    ll square_sum=0;
    for(int j=0;j<n;j++){
        square_sum=(square_sum+(a[j]*a[j])%mod)%mod;
    }
    ll modinv=modInverse(2);
    // printf("%llu\n",modinv);
    ll ans=(((sum-square_sum+mod)%mod)*modinv)%mod;
    printf("%llu\n",ans);
    return 0;
}