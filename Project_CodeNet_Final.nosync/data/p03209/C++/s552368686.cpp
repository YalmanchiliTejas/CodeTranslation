#include <iostream>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
ll N, X;
ll nums[51];
ll ps[51];

ll dfs(ll X, ll N){
    if(N == 0) return 1;
    if(X == 1) return 0;
    else if(X >= 2 && X <= nums[N-1] + 1) dfs(X-1, N-1);
    else if(X == nums[N-1] + 2) return ps[N-1] + 1;
    else if(X >= nums[N-1] + 3 && X <= nums[N-1] * 2 + 2) return ps[N-1] + 1 + dfs(X-nums[N-1]-2, N-1);
    else return ps[N];
}

int main(){
    cin >> N >> X;

    nums[0] = 1;
    ps[0] = 1;
    for(int i=1; i<=N; i++){
        nums[i] = 2ll*nums[i-1] + 3;
        ps[i] = 2ll*ps[i-1] + 1;
    }

    ll ans = dfs(X, N);
    cout << ans << endl;
    
    return 0;
}
