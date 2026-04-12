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
#include <cstring>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
const int nmax = 3010;
ll dp[nmax][nmax];
bool visited[nmax][nmax];
int n;
ll ary[nmax];

ll rec(int x, int y)
{
    // [x,y)におけるX-Yを求める
    if (visited[x][y]) return dp[x][y];
    if (y-x==1)
    {
        visited[x][y] = true;
        return dp[x][y] = ary[x];
    }

    visited[x][y] = true;
    return dp[x][y] = max(ary[x]-rec(x+1,y), ary[y-1]-rec(x, y-1));
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    rep(i,n) cin >> ary[i];
    rep(i,nmax) rep(j,nmax) visited[i][j] = false;

    cout << rec(0, n) << endl;
}
