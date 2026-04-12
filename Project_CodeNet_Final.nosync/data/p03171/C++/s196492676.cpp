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
#define fi first
#define se second
#define pt(num) cout << num << "\n"
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 100010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;




int main(void) {
    ll N;
    cin >> N;
    ll a[3333];
    ll i, j;
    ll dp[3333][3333]={};
    
    for(i=0; i<N; i++) {
        cin >> a[i];
    }
    
    for(i=N-1; i>=0; i--) {
        for(j=1; j<=N; j++) {
            if(i>=j) continue;
            
            if(N%2==(j-i)%2)
                dp[i][j]=max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
            else
                dp[i][j]=min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
        }
    }
    
    pt(dp[0][N]);
    
}


