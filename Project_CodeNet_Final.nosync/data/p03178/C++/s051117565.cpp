#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for( int i = l; i < r; i++ )
#define vi vector<int>
#define pb push_back
#define li long long int
#define st string

int mod = 1e9+7;

void addMod( li & a, li b ) {
    a = (a+b);
    while( a >= mod ) a -= mod;
}

int main() {
    st s; cin>>s;
    int d; cin>>d;
    li dp[s.length()+2][d+2][10];
    FOR(i,0,s.length()+2) FOR(j,0,d+2) FOR(k,0,10) dp[i][j][k] = 0;
    FOR(i,0,10) addMod(dp[1][i%d][i],1);
    FOR(i,2,s.length()+2) {
        FOR(j,0,10) {
            FOR(k,0,d) {
                FOR(h,0,10) addMod(dp[i][(j+k)%d][j],dp[i-1][k][h]);
            }
        }
    }
    int dig = s.length();
    li ans = 0;
    li accum = 0;
    FOR(i,0,dig) {
        int num = s[i]-'0';
        FOR(k,0,num) addMod(ans,dp[dig-i][(d-accum)%d][k]);
        accum = (accum+num)%d;
    }
    if( accum%d == 0 ) ans++; 
    cout<<(ans-1+mod)%mod<<"\n";
    return 0;
}