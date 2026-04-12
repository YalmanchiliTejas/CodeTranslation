#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int N,a[3010];

int dp[3010][3010];
const int INF=1e18;

int rec(int i,int j)
{
    if(i==j) return 0;
    if(dp[i][j]>=0) return dp[i][j];
    
    if(N%2==(j-i)%2){
        int res=-INF;
        chmax(res,a[i]+rec(i+1,j));
        chmax(res,a[j-1]+rec(i,j-1));
        return dp[i][j]=res;
    }else{
        int res=INF;
        chmin(res,rec(i+1,j));
        chmin(res,rec(i,j-1));
        return dp[i][j]=res;
    }
}

signed main()
{
    cin>>N; 
    for(int i=0;i<N;i++){
        cin>>a[i];
    }

    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j]=-INF;
        }
    }
    cout<<2*rec(0,N)-accumulate(a,a+N,0LL)<<endl;
}
