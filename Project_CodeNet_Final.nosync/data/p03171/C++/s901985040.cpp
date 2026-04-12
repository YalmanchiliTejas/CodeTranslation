#include<bits/stdc++.h>
typedef long long ll;
typedef double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
 
const ll inf = 1e9;
const ll N = 3005;
const ll bits = 21;
const ll mod = 1e9+7;
const ld pi = 3.14159265358979323846;
 
ll dp[N][N][2],arr[N];

int main(){
    FASTIO;
    PRECISION;

    ll n,temp;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];

        dp[i][i][0] = arr[i];
        dp[i][i][1] = -arr[i];
    }



    for(int sz = 2;sz<=n;sz++){
        for(int i=1;i+sz-1<=n;i++){
            int j = i+sz-1;

            dp[i][j][0] = max(arr[i]+dp[i+1][j][1],arr[j]+dp[i][j-1][1]);
            dp[i][j][1] = min(-arr[i]+dp[i+1][j][0],-arr[j]+dp[i][j-1][0]);
        }
    }

    cout<<dp[1][n][0]<<"\n";
}