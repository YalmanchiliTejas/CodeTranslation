
///╔══╗
///╚╗╔╝
///╔╝╚(¯`v´¯)
///╚══╝`.¸.´farzin


#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define ibsws ios_base::sync_with_stdio
#define gcd __gcd
#define s second
#define f first
#define mp make_pair
typedef std::pair<int,int> pii ;

using namespace std;

const int N=3e3+10;
int n,a[N],dp[N][N][2];

int32_t main(){
	ibsws(true==false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        dp[i][i][1]=-1*a[i];
        dp[i][i][0]=a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            dp[j][j+i][0]=max(dp[j+1][j+i][1]+a[j],dp[j][j+i-1][1]+a[j+i]);
            dp[j][j+i][1]=min(dp[j+1][j+i][0]-a[j],dp[j][j+i-1][0]-a[j+i]);
        }
    }
    cout<<dp[0][n-1][0];
}
