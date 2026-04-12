#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>

using namespace std;
int N;
long long burger[51][2];

long long dp(int N,long long X) {
    long long res = 0;
    if(X==0)return 0;
    if(N==0)return 1;
    if(burger[N-1][0]+1>=X){
        return dp(N-1,X-1);
    }else{
        return burger[N-1][1]+1+dp(N-1,X-burger[N-1][0]-2);
    }
}
// 9
//BBPPPBPBPPPBB
//B,BPPPB,P,BPPPB,B

int main() {
    int i;
    long long X;
    cin>>N>>X;
    burger[0][0]=1;
    burger[0][1]=1;
    for(i=1;i<=N;i++){
        burger[i][0]=1+burger[i-1][0]+1+burger[i-1][0]+1;
        burger[i][1]=(burger[i-1][1]*2)+1;
        // cout<<burger[i][0]<<" "<<burger[i][1]<<endl;
    }
    cout<<dp(N, X);
    return 0;
}