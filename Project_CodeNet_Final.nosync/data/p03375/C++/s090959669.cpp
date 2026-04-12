#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define All(A) A.begin(),A.end()
#define RAll(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<double,double> P;
LL mod;
const LL LINF=1LL<<62;
const LL INF=1<<30;

vector<LL> fact;
vector<LL> inver(200001);

LL combination(int n,int r){
    if(n<r||n<0||r<0) return 0;
    return fact[n]%mod*inver[n-r]%mod*inver[r]%mod;
}

LL fpow(LL a, LL n,LL m){
    LL x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%m;
        }
        a=a*a%m;
        n >>= 1;
    }
    return x;
}

LL dp[3001][3001];
LL ways[3001];

//iをjに分割する個数
LL rec(int i,int j){
    if(dp[i][j]) return dp[i][j];
    if(i<j) return 0;
    else if(i==j||j==0) return 1;
    else return dp[i][j]=(rec(i-1,j-1)+(j+1)*rec(i-1,j))%mod;
}

int main(){
    int N;
    cin >> N >> mod;
    LL s=1;
    fact.push_back(1);
    for(int i=1;i<=200000;i++){
        s*=i;
        s%=mod;
        fact.push_back(s);
    }
    inver[200000]=fpow(fact[200000],mod-2,mod);
    for(int i=199999;i>=0;i--){
        inver[i]=inver[i+1]*(i+1)%mod;
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            ways[i]=(ways[i]+rec(i,j)*fpow(2,(N-i)*j,mod))%mod;
        }
        ways[i]*=fpow(2,fpow(2,N-i,mod-1),mod);
        ways[i]%=mod;
    }
    LL ans=0;
    for(int i=0;i<=N;i++){
        if(i%2) ans=(ans+mod-(combination(N,i)*ways[i])%mod)%mod;
        else ans=(ans+combination(N,i)*ways[i])%mod;
    }
    cout << ans << endl;
    return 0;
}