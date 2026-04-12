#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

ll fact[200000], invFact[200000]; 

long long power(long long x, long long c) {
    if(c==0) return 1;
    if(c==1) return x;
    if (c%2==1) return (power( (x*x)%MOD, c/2)*x)%MOD;
    else return power( (x*x)%MOD, c/2)%MOD;
}

void make_combT(ll n){
    fact[0]=1;
    rep1(i,n) fact[i]= fact[i-1]*i%MOD;
    
    invFact[n] = power(fact[n],MOD-2);
    rrep(i,n-1) invFact[i] = invFact[i+1] * (i+1) %MOD;
}

ll comb(ll n, ll m){
    if(n<m||n<0||m<0) return 0;
    return (fact[n] * invFact[m] %MOD) * invFact[n-m] %MOD;
}

ll dp[1009][1009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make_combT(20009);
    
    int N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    
    rep(i,1009) dp[i][0]=1;
    for(int i=A;i<=B;i++){
        rep(j,N+1)if(dp[i][j]){
            if(j) (dp[i+1][j]+=dp[i][j])%=MOD;
            ll p=1;
            for(int k=1;k<=D&&j+i*k<=N;k++){
                p=(((p*comb(N-j-i*(k-1),i)%MOD)*power(k,MOD-2))%MOD)%MOD;
                if(k>=C) (dp[i+1][j+i*k]+=(dp[i][j]*p)%MOD)%=MOD;
            }
        }
    }
    cout1(dp[B+1][N])
}