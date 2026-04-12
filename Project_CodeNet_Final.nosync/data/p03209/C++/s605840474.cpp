#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;


LL dp[51];
LL p[51];

LL dfs(LL x,LL k){
    LL ret=0;
    if(x<0) return 0;
    if(k==0) return 1;
    if(x>dp[k]/2){
        ret=dfs(x-dp[k]/2-1,k-1)+p[k-1]+1;
    }
    else if(x==dp[k]/2){
        ret=p[k-1]+1;
    }
    else{
        ret=dfs(x-1,k-1);
    }
    return ret;
}


int main(){
    LL N,X;cin >> N >> X;
    dp[0]=1;
    p[0]=1;
    for (int i = 0; i < N; i++) {
        dp[i+1]=2*dp[i]+3;
        p[i+1]=2*p[i]+1;
    }
    if(X==1){
        cout << 0 << endl;
        return 0;
    }
    cout << dfs(X-1,N) << endl;
    return 0;
}

