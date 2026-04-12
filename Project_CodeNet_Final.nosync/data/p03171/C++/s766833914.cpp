#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int inf = 1e8;
ll dp[3000][3000];
ll findansrec(int index, int n, ll ptr[]){
    if(index==n) return 0;
    if(dp[index][n-1]!=-1) return dp[index][n-1];
    if( (ptr[index] - findansrec(index+1,n,ptr)) >
        (ptr[n-1] - findansrec(index,n-1,ptr)) ){
            return dp[index][n-1] = (ptr[index] - findansrec(index+1,n,ptr));
    }else{
            return dp[index][n-1] = (ptr[n-1] - findansrec(index,n-1,ptr));
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    ll ptr[n];
    for(int i = 0 ; i <n; i++) cin>>ptr[i];
    cout<<findansrec(0,n,ptr);
}