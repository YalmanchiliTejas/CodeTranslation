#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define mkp make_pair
#define pr(num) cout << num << "\n"
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 100010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

int main(void) {
    string N;
    ll D;
    cin >> N >> D;
    ll dp[N.size()+5][D+5][2];
    ll i, j, l;
    memset(dp, 0, sizeof(dp));
    dp[0][0][1]=1;
    
    for(i=0; i<N.size(); i++) {
        for(j=0; j<D; j++) {
            
            for(l=0; l<10; l++) {
                dp[i+1][(j+l)%D][0]+=dp[i][j][0];
                dp[i+1][(j+l)%D][0]%=MOD;
            }
            
            for(l=0; l<N[i]-'0'; l++) {
                dp[i+1][(j+l)%D][0]+=dp[i][j][1];
                dp[i+1][(j+l)%D][0]%=MOD;
            }
            
            dp[i+1][(j+N[i]-'0')%D][1]+=dp[i][j][1];
            dp[i+1][(j+N[i]-'0')%D][1]%=MOD;
        }
    }
    
    ll ans=dp[N.size()][0][0]+dp[N.size()][0][1];
    ans--;
    pr((ans+MOD)%MOD);
}
