#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

int main(){
    int N;cin>>N;
    int x=N%2,y=(N+1)%2;
    int a[3010];
    for(int i=0;i<N;i++)cin>>a[i];
    mat dp(3010,vec(3010));
    for(int i=0;i<=N;i++)dp[i][i]=0;
    
    int i=N-1;
    while(i>=0){
        int j=i+1;
        while(j<=N){
            if((j-i)%2==x)
                dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
            if((j-i)%2==y)
                dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
            j++;
        }
        i--;
    }
    cout<<dp[0][N]<<endl;
    return 0;
}