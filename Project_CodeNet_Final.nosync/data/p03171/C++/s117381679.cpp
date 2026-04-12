#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const int INF=1000000000;

vector<LL> X;
LL memo[3001][3001][2];
int N;

LL dfs(int a,int b,int c){
    if(~memo[a][b][c]) return memo[a][b][c];
    if(a==b) return memo[a][b][c]=0;
    LL ret=0;
    if(!c){
        ret=max(dfs(a+1,b,c^1)+X[a],dfs(a,b-1,c^1)+X[b-1]);
    }
    else{
        ret=min(dfs(a+1,b,c^1)-X[a],dfs(a,b-1,c^1)-X[b-1]);
    }
    return memo[a][b][c]=ret;
}



int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        LL x;cin >> x;
        X.pb(x);
    }
    memset(memo,-1,sizeof(memo));
    cout << dfs(0,N,0) << endl;
    return 0;
}

