#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

LL dp[1002][1001];
vector<LL> fact;
vector<LL> inver(1001);

LL combination(int n,int r){
    if(n<0||r<0||n<r) return 0;
    return fact[n]%mod*inver[n-r]%mod*inver[r]%mod;
}

LL fpow(LL a, LL n){
    int x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%mod;
        }
        a=a*a%mod;
        n >>= 1;
    }
    return x;
}

int main(){
    int N;
    cin >> N;
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    LL s=1;
    fact.push_back(1);
    for(int i=1;i<=1000;i++){
        s*=i;
        s%=mod;
        fact.push_back(s);
    }
    inver[1000]=fpow(fact[1000],mod-2);
    for(int i=999;i>=0;i--){
        inver[i]=inver[i+1]*(i+1)%mod;
    }
    dp[A][0]=1;
    for(int i=A;i<=B;i++){
        for(int j=0;j<=N;j++){
            LL sum=1;
            (dp[i+1][j]+=dp[i][j])%=mod;
            for(int k=1;k<C;k++){
                (sum*=combination(N-(j+(k-1)*i),i))%=mod;
            }
            for(int k=C;j+k*i<=N&&k<=D;k++){
                (sum*=combination(N-(j+(k-1)*i),i))%=mod;
                (dp[i+1][j+k*i]+=dp[i][j]*sum%mod*(inver[k]%mod))%=mod;
            }
        }
    }
    cout << dp[B+1][N]%mod << endl;
    return 0;
}