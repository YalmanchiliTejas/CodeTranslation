#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int dp[100000]={};//0は何も入っていない。1はまだマジックを使っていないボールが入っている。2はマジックを使ったボールが入っていることを示している。 添え字は 0 ~ (N-1)

int main(){
    int N,Q;
    cin>>N>>Q;
    dp[0]=1;
    for(int q=1;q<=Q;q++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        if(a-1>=0 && dp[a-1]==1){
            dp[a]=2;
        }
        if(dp[a]==1){
            if(a-1>=0) dp[a-1]=2;
            if(a+1<N) dp[a+1]=2;
        }
        if(a+1<N && dp[a+1]==1){
            dp[a]=2;
        }
        if(b-1>=0 && dp[b-1]==1){
            dp[b]=2;
        }
        if(dp[b]==1){
            if(b-1>=0) dp[b-1]=2;
            if(b+1<N) dp[b+1]=2;
        }
        if(b+1<N && dp[b+1]==1){
            dp[b]=2;
        }
        int c = dp[a];
        dp[a]=dp[b];
        dp[b]=c;
    }
    for(int i=0;i<N;i++){
        if(dp[i]==1){
            if(i-1>=0) dp[i-1]=2;
            if(i+1<N) dp[i+1]=2;
        }
    }
    int res=0;
    for(int i=0;i<N;i++){
        if(dp[i]!=0){
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
