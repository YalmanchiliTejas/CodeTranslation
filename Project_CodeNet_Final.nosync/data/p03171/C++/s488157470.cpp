#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dp[3030][3030][2];
ll a[3030];

ll rec(int x,int y,int idx){
    if(dp[x][y][idx]!=longinf)return dp[x][y][idx];
    if(x==y){
        if(idx)return a[x];
        else return -a[x];
    }
    if(idx)return dp[x][y][idx]=max(a[x]+rec(x+1,y,1-idx),a[y]+rec(x,y-1,1-idx));
    else return dp[x][y][idx]=min(-a[x]+rec(x+1,y,1-idx),-a[y]+rec(x,y-1,1-idx));
}

int main(){
    int n;
    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)rep(j,n)rep(k,2)dp[i][j][k]=longinf;
    cout<<rec(0,n-1,1)<<endl;
    return 0;
}