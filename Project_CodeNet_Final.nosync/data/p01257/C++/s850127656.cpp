#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF=1000000000;

int N,M;
int coins[101];
int dp[100001];
int summ[1<<11];

int main(){
    while(cin>>N>>M&&(N|M)){
        for(int i=0;i<N;i++)cin>>coins[i];
        for(int i=0;i<(1<<N);i++){
            summ[i]=0;
            for(int j=0;j<N;j++)if((i>>j)&1)summ[i]+=coins[j];
        }
        for(int i=0;i<=M;i++){
            int res=INF;
            if(i==0)res=0;
            else{
                for(int j=1;j<(1<<N);j++){
                    if(i-summ[j]>=0)res=min(res,dp[i-summ[j]]+1);
                }
            }
            dp[i]=res;
        }
        cout<<dp[M]<<endl;
    }

    return 0;
}