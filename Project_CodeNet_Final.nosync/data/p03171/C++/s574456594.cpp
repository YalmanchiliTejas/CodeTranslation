#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<queue>
#include<functional>
#include<iso646.h>
#include<bitset>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e10;
const ll MOD = 1e9 + 7;
const ll MAX_N = 3e3 + 10;
ll dp[MAX_N][MAX_N];

int main(){
    ll i, j;
    ll N;
    cin>>N;
    vll A(N);
    for(auto &e: A)cin>>e;
    bool odd = (N%2 == 1);

    for(i = 0; i<N; i++){
        if(odd){
            dp[i][i] = A[i];
        }
        else{
            dp[i][i] = -A[i];
        }
        // cout<<dp[i][i]<<endl;
    }
    for(i = 1; i < N; i++){
        for(j = 0; j < N - i; j++){
            if(i%2 == N%2){
                dp[j][j + i] = min(dp[j][j + i - 1] - A[j + i], dp[j + 1][j + i] - A[j]);
                // cout<<dp[j][j + i]<<endl;
            }
            else{
                dp[j][j + i] = max(dp[j][j + i - 1] + A[j + i], dp[j + 1][j + i] + A[j]);
                // cout<<dp[j][j + i]<<endl;
            }
        }
    }
    cout<<dp[0][N - 1]<<endl;

    return 0;
}