#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }


signed main()
{
    int N; cin>>N;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    
    vector<vector<int> > dp(N+1,vector<int>(N+1));
    for(int i=0;i<=N;i++){
        dp[i][i]=0;
    }
    
    for(int len=1;len<=N;len++){
        for(int i=0;i+len<=N;i++){
            int j=i+len;
            if((N-len)%2==0){
                dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
            }else{
                dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
            }
        }
    }
    cout<<dp[0][N]<<endl;
}
