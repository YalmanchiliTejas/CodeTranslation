#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define inf 1001001001001000
#define mod 1000000007
#define pi 3.1415926535
using namespace std;
ll dp[101][4][2];
int main(void){
    string n;
    cin>>n;
    ll K;
    cin>>K;
    dp[0][0][1] = 1;
    rep(i,n.size()) rep(j,4) rep(k,2){
        rep(l,10){
            ll ni=i+1,nj=j,nk=k;
            if(l != 0) nj++;
            if(nj > K) continue;
            if(k == 1){
                if(l<n[i]-'0') nk = 0;
                if(l>n[i]-'0') continue;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    ll ans = dp[n.size()][K][0]+dp[n.size()][K][1];
    cout<<ans<<endl;
}
