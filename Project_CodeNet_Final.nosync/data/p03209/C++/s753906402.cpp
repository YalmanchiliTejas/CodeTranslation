#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
ll N,X;
vector<ll> A,B;
ll dfs(int i, ll x){
    if(i == 0)return 1;
    if(x == 1)return 0;
    if(x == A[i-1] + 2)return B[i-1] + 1;
    if(x == A[i-1] * 2 + 3)return B[i];
    if(x < A[i-1] + 2){
        return dfs(i-1, x-1);
    }else{
        return dfs(i-1, x-(A[i-1]+2)) + B[i-1] + 1;
    }
}
main(){
    cin >> N >> X;
    A.resize(N+1);
    B.resize(N+1);
    A[0] = B[0] = 1;
    rep(i,0,N){
        A[i+1] = A[i] * 2 + 3;
        B[i+1] = B[i] * 2 + 1;
    }
    cout << dfs(N, X) << endl;
}