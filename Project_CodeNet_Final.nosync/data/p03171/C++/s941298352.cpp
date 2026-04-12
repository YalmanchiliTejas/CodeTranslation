#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


ll DP[3010][3010];
int N;
ll a[3000];
ll solve(int i, int j){//i:jから始めたときのX-Yを求める関数。
    if (DP[i][j] != -1) {
        return DP[i][j];
    }
    if (j-i == 1){
        return a[i];
    }
    ll st = a[i];
    ll en = a[j-1];
    if ((N - (j-i)) % 2 == 0){//X-Yを最大化する。今から求めるのはX。
        if (j-i == 2){
            DP[i][j] = max(st - en, en - st);
        }else{
            DP[i][j] = max(st + solve(i+1, j), solve(i, j-1) + en);
        }
    }else{//X-Yを最小化する。今から取るのはY。
        if (j-i == 2){
            DP[i][j] = min(st - en, en - st);
        }else{
            DP[i][j] = min(solve(i+1, j) - st, solve(i, j-1) - en);
        }
    }
    return DP[i][j];
}
int main() {
    cin >> N;
    REP(i, N) {
        cin >> a[i];
    }
    REP(i, N+1) {
        REP(j, N+1) {
            DP[i][j] = -1;
        }
    }
    cout << solve(0, N);

}