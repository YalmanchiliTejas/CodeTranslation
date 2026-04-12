#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX_N 3000

int n;
ll a[MAX_N];
ll dp[2][MAX_N + 1][MAX_N + 1];
bool visited[2][MAX_N + 1][MAX_N + 1];

ll rec(bool turn, int left, int right){
    if(visited[turn][left][right]) return dp[turn][left][right];
    visited[turn][left][right] = true;
    if(left == right){
        if(turn) return dp[turn][left][right] = a[left];
        else return dp[turn][left][right] = -a[left];
    }
    ll res;
    if(turn){
        res = -LINF;
        res = max(res, rec(!turn, left + 1, right) + a[left]);
        res = max(res, rec(!turn, left, right - 1) + a[right]);
    }else{
        res = LINF;
        res = min(res, rec(!turn, left + 1, right) - a[left]);
        res = min(res, rec(!turn, left, right - 1) - a[right]);
    }
    return dp[turn][left][right] = res;
}

signed main(){
    cin >> n;
    REP(i,n){
        cin >> a[i];
    }
    cout << rec(true, 0, n - 1) << endl;
    return 0;
}