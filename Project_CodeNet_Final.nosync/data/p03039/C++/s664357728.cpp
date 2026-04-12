#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int mod_pow(long long int a, long long int e, int p){
    long long int res = 1;
    for(;e>0;e>>=1){
        if(e&1)res=(res*a)%p;
        a=(a*a)%p;
    }
    return (int)res;
}

int fact(int n, int p){
    static int F[1000001];
    if(F[n]) return F[n];
    else{
        F[0]=1;
        for(long long int i=1;i<=1000000;i++){
            F[i]=i*F[i-1]%p;
        }
        return F[n];
    }

    long long int res=1;
    while(n){
        res*=n;
        if(res>p)res%=p;
        if(res==0)return 0;
        n--;
    }
    return (int)res;
}

int mod_fact(int n,int p,int &e){
    static int F[1000001];
    if(F[n]) return F[n];
    e=0;
    if(n==0)return 1;
    long long int res=mod_fact(n/p,p,e);
    e+=n/p;
    if(n/p%2!=0) return F[n]=res*(p-fact(n%p,p))%p;
    return F[n]=res*fact(n%p,p)%p;
}

int mod_comb(int n, int k,int p){
    if(n<0||k<0||n<k)return 0;
    int e1,e2,e3;
    long long int a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
    //if(e1>e2+e3)return 0;
    //return (a1*mod_inverse(a2*a3%p,p))%p;
    return a1*mod_pow(a2*a3%p,p-2,p)%p;
}

int main(){
    int64_t N,M,K;
    cin>>N>>M>>K;
    int64_t sum=0;
    int64_t mod=1000000007;
    for(int i=2;i<=M;i++){
        int64_t s=N*N%mod;
        (s*=M-i+1)%=mod;
        (s*=i-1)%=mod;
        (sum+=s)%=mod;
    }
    for(int i=2;i<=N;i++){
        int64_t s=M*M%mod;
        (s*=N-i+1)%=mod;
        (s*=i-1)%=mod;
        (sum+=s)%=mod;
    }
    (sum*=mod_comb(N*M-2,K-2,mod))%=mod;
    cout<<sum<<endl;
    return 0;
}