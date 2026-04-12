#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <bitset>
#include <time.h>
#include <set>
#include <algorithm>
#define ll long long
#define MAXN 1000
#define MODD 1000000007
#define ll long long
using namespace std;
ll fact[MAXN+1];
ll factinv[MAXN+1];

ll modpow(ll x, ll y) {
    x%=MODD;
    ll xs = x;
    ll answer = 1;
    while(y) {
        if (y&1) {
            answer = (answer * xs) % MODD;
        }
        y >>= 1;
        xs = (xs * xs) % MODD;
    }
    return answer;
}

ll binomial[MAXN+2][MAXN+2];
ll dp[MAXN+10][MAXN+10];

ll Solve(int left,int pos,int A,int B,int C,int D) {
    if (pos == B+1) {
        return (left == 0);
    }
    
    if (dp[left][pos]!=-1)
        return dp[left][pos];
    
    
    // either sz=0;
    ll answer = Solve(left,pos+1,A,B,C,D);
    for(int y=C;y<=D;y++) {
        if (left-y*pos < 0)
            break;
        ll curr = fact[y*pos]*modpow(factinv[pos],y)%MODD;
        curr = (curr * factinv[y])%MODD;
        curr = (curr * binomial[left][y*pos])%MODD;
        answer +=   curr*Solve(left-y*pos,pos+1,A,B,C,D)%MODD;
        if (answer > MODD)
            answer -= MODD;
    }
    return dp[left][pos]=answer;
    
    
}

// 12,34
// 13,24
// 14,23

int main() {
    fact[0]=factinv[0]=1;
    for(int i=1;i<=MAXN;i++) {
        fact[i]=(fact[i-1]*i)%MODD;
        factinv[i]=modpow(fact[i], MODD-2);
    }
    
    for(int i=0;i<=MAXN;i++)
        for(int j=0;j<=i;j++) {
            binomial[i][j]=(j==0?1:(binomial[i-1][j]+binomial[i-1][j-1])%MODD);
        }
    
    
    int N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;

    for(int i=0;i<=N+1;i++)
        for(int j=0;j<=N+1;j++)
            dp[i][j]=-1;
    
    cout << Solve(N,A,A,B,C,D)%MODD << endl;
    
    
    
}