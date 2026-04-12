#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

const ll INF = 1'000'000'000'000'000'000LL;

int N;
ll A[200000];

ll memo[200000][3];
bool visited[200000][3] ={};
ll solve(int n, int nokori){
    if(nokori < 0) return -INF;
    if(n >= N) return 0;
    if(n+2 >= N && nokori == 2) return 0;
    if(visited[n][nokori]) return memo[n][nokori];
    visited[n][nokori] = true;
    return memo[n][nokori] = max(solve(n+2, nokori)+A[n], solve(n+1, nokori-1));
}

signed main(){
    cin >> N;
    rep(i, N) cin >> A[i];
    if(N%2 == 0) cout << solve(0, 1) << endl;
    else cout << solve(0, 2) << endl;
}