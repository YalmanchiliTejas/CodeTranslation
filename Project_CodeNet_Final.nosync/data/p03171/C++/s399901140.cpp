#include <iostream>

using namespace std;

typedef long long ll;

#define MAXN 3005

ll arr[MAXN];

ll dp[MAXN][MAXN];

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);

    int n;cin>>n;

    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int r = 1;r<=n;r++){
        for(int l = r;l>0;l--){
            dp[r][l] = max(arr[l] - dp[r][l+1], arr[r] - dp[r-1][l]);

        }

    } 

    cout<<dp[n][1]<<endl;

}
