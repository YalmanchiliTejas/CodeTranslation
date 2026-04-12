#include <iostream>
using namespace std;

const int maxN=3001;

int n;
int v[maxN];

long long dp[maxN][maxN];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    for(int i=1;i<=n;i++){
        dp[i][i]=v[i];
    }

    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    }

    cout<<dp[1][n];

    return 0;
}