#include<iostream>
#include<stdio.h>
#include<vector>
#include<ctype.h>
#include<string>
#include<cmath>
#include<string.h>
#include<sstream>
#include<limits.h>
#include<regex>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

//最大公約数
int gcd(int a,int b){
    return b ? gcd(b,a%b):a;
}

//最小公倍数
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

//素数判定
bool isPrime(int x){
    if(x<2)return 0;
    else if(x==2)return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0)return 0;
    }
    return 1;
}

//桁ごとの足し算
int digsum(int n){
    int res=0;
    while(n>0){
        res+=n%10;
        n/=10;
    }
    return res;
}

//約数列挙
vector<int> enum_div(int n){
    vector<int> ret;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            ret.push_back(i);
            if(i*i !=n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

//累乗の計算とあまり,0で累乗そのまま出力
long long modpow(long long a,long long n,long long mod){
    if(mod==0)mod=__LONG_LONG_MAX__;
    long long res=1;
    while(n>0){
        if(n & 1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int N;

int main(){
    cin>>N;
    vector<ll> A(N);
    vector<ll> sum(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(i==0){
            sum[i]=A[i];
        }
        else sum[i]=sum[i-1]+A[i];
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        ans+=A[i]*((sum[N-1]-sum[i])%1000000007);
        ans%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}