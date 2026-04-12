#include <bits/stdc++.h>
using namespace std;///0 es el turno de Taro y 1 el turno de jiro
long long  n,ans1,ans2;
vector<long long > deq;
long long  dp[3010][3010][2];

long long  recur(long long  id1,long long  id2, long long  turn){
    if(id1 == id2) return (turn == 0 ? deq[id1] : -deq[id1]);
    if(dp[id1][id2][turn] != -1) return dp[id1][id2][turn];
    else{
        if(turn == 0){
            return dp[id1][id2][turn] = max(deq[id1] + recur(id1+1,id2,1), deq[id2] + recur(id1,id2-1,1));
        }else{
            return dp[id1][id2][turn] = min(recur(id1+1,id2,0) - deq[id1],recur(id1,id2-1,0) - deq[id2]);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n;
    deq.resize(n);
    memset(dp,-1,sizeof dp);
    for(long long  i = 0 ; i < n; i++) cin>>deq[i];
    cout<<recur(0,n-1,0);
}
