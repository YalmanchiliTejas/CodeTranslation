#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;
ll dp[3010][3010];

int main(){
    int n;
    cin>>n;
    vector<int> a(n+2);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<3010;i++) dp[i][i]=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if((n-i-1)%2==0){
                dp[j-1-i][j]=max(dp[j-1-i][j-1]+a[j-1],a[j-1-i]+dp[j-i][j]);
            }else{
                dp[j-1-i][j]=min(dp[j-1-i][j-1]-a[j-1],-a[j-1-i]+dp[j-i][j]);
            }
        }
    }
    cout<<dp[0][n]<<endl;
    return 0;
}