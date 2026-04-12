#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=2019;

int main(){
    string N; cin >> N;
    int K; cin >> K;
    int size=N.size();
    vector<vector<vector<ll>>> dp(size, vector<vector<ll>>(2, vector<ll>(K+1, 0)));
    dp[0][0][0]=1;
    dp[0][0][1]=N[0]-'0'-1;
    dp[0][1][1]=1;
    for(int i=1; i<size; i++){
        for(int j=0; j<=K; j++){
            if(j == 0){
                dp[i][0][j]=dp[i-1][0][j];
            }
            else{
                dp[i][0][j]=dp[i-1][0][j-1]*9+dp[i-1][0][j];
                if(N[i] != '0'){
                    dp[i][0][j]+=dp[i-1][1][j-1]*(N[i]-'0'-1)+dp[i-1][1][j];
                    dp[i][1][j]=dp[i-1][1][j-1];
                }
                else dp[i][1][j]=dp[i-1][1][j];
            }
        }
    }
    cout << (dp[size-1][0][K]+dp[size-1][1][K]) << endl;
    return 0;
}