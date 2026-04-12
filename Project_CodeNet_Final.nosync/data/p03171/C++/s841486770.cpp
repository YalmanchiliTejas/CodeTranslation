#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll INF = 50000000000000LL;

ll f(vector<vector<ll>>& dp, const vector<int>& A, int N, int beg, int end){
    if(dp[beg][end] != INF)return dp[beg][end];
    // cout<<beg<<" "<<end<<endl;
    if(end - beg == 1){
        dp[beg][end] = abs(A[end]-A[beg]);
        return dp[beg][end];
    }
    ll x = A[beg] - f(dp,A,N,beg+1,end);
    ll y = A[end] - f(dp,A,N,beg,end-1);
    dp[beg][end] = max(x,y);
    return dp[beg][end];
}

int main(){
    int N;cin>>N;
    vector<int> A;
    for(int i = 0;i < N;i++){
        int _a;cin>>_a;
        A.push_back(_a);
    }
    if(N == 1){
        cout<<A[0]<<endl;
        return 0;
    }
    vector<vector<ll>> dp(N,vector<ll>(N,INF));
    cout<<f(dp,A,N,0,N-1)<<endl;
}