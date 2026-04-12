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

int D;
string K;
LL memo[100001][2][101];


int dfs(int k,bool t,int p){
    if(~memo[k][t][p]) return memo[k][t][p];
    if(k==K.length()) return memo[k][t][p]=(p%D==0?1:0);
    int x=(t?K[k]-'0':9);
    LL ret=0;
    for (int i = 0; i <= x; i++) {
        ret+=dfs(k+1,t&(i==x?1:0),(p+i)%D);    
    }
    return memo[k][t][p]=ret%mod;
}



int main(){
    cin >> K >> D;
    memset(memo,-1,sizeof(memo));
    cout << (dfs(0,1,0)+mod-1)%mod << endl;
    return 0;
}

