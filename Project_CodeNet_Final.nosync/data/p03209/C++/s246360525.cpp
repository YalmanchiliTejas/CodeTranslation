#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

#define FOR(i,a,b) for(long long i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define FORR(i,a,b) for(long long i=(a);i>=(b);--i)
#define REPR(i,n)   FORR(i,n,0)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;

ll N,X;
    ll dp[2][52];

ll eat(ll x,ll n){
    if(n==0){
        if(x>=1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(x>=dp[0][n]){
        return dp[1][n];
    }
    else if(x<=dp[0][n-1]+1LL){
        return eat(x-1LL,n-1LL);
    }
    else if(x==dp[0][n-1]+2LL){
        return dp[1][n-1]+1LL;
    }
    else{
        return dp[1][n-1]+1LL+eat(x-dp[0][n-1]-2LL,n-1LL);
    }
}

int main() {
	
    cin>>N>>X;
    
    dp[0][0]=1,dp[1][0]=1;
    FOR(i,1,N+1){
        dp[0][i]=dp[0][i-1]*2+3;
        dp[1][i]=dp[1][i-1]*2+1;
    }

    ll ans=eat(X,N);
    cout<<ans<<endl;

	return 0;
}
