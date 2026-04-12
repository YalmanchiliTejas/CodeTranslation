#include <bits/stdc++.h>
using namespace std;
#define int long long

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>=0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define ll long long
const int mod=1e9+7;
const ll MX=1<<30;

ll powmod(ll n,ll k){
    if (k==0) return 1;
    else if (k%2==0){
        ll tmp=powmod(n,k/2);
        return tmp*tmp%mod;
    }
    else return powmod(n,k-1)*n%mod;
}

int n,a,b,c,d;
ll dp[1005][1005];
ll fact[1005],fact1[1005][1005],fact2[1005];
ll comb[1005][1005];

signed main()
{
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    rep(i,n+1){
        dp[i][0]=1;
    }
    fact[0]=1;
    rep2(i,1,n+1){
        fact[i]=fact[i-1]*i%mod;
        fact2[i]=powmod(fact[i],mod-2);
    }
    rep2(i,1,n+1){
        rep(k,n+2){
            fact1[i][k]=powmod(fact[i],(mod-2)*k);
        }
    }
    comb[0][0]=1;
    rep2(i,1,n+1){
        comb[i][0]=1;
        rep2(j,1,n+1){
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
        }
    }
    rep2(i,1,n+1){
        if(i<a) continue;
        rep2(j,1,n+1){
            if(j<a) continue;
            rep(k,j/i+1){
                if(d<k) break;
                if((c<=k&k<=d)&(a<=i&i<=b)){
                    ll tmp=fact1[i][k]*fact2[k]%mod;
                    dp[i][j]+=comb[n-j+i*k][i*k]*fact[i*k]%mod*tmp%mod*dp[i-1][j-i*k]%mod;
                    dp[i][j]%=mod;
                }
                else if(k==0){
                    dp[i][j]+=dp[i-1][j];
                    dp[i][j]%=mod;
                }
            }
        }
    }
    printf("%lld\n", dp[n][n]);
}
