#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int Dy[8] = {-1,-1,0,1,1,1,0,-1};
int Dx[8] = {0,1,1,1,0,-1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
int n,a[3030],dp[3030][3030];

int f(int i,int j){
    if(i==j)dp[i][j]=a[i];
    if(dp[i][j]==-1)dp[i][j]=max(a[i]-f(i+1,j),a[j]-f(i,j-1));
    return dp[i][j];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    //dp[i][j]:ai~ajでゲームをした時のスコア
    cout<<f(0,n-1)<<endl;
}