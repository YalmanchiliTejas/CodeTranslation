#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

vector<ll> a;
ll dp[3001][3001][2];

ll calc(ll left, ll right, int hand){
    if(left == right){
        return 0;
    }
    if(dp[left][right][hand] != -1){
        return dp[left][right][hand];
    }

    if(hand == 0){
        dp[left][right][hand] = max(
            calc(left, right - 1, 1) + a.at(right -1),
            calc(left + 1, right, 1) + a.at(left)
        );
    }else{
        dp[left][right][hand] = min(
            calc(left, right - 1, 0) - a.at(right -1),
            calc(left + 1, right, 0) - a.at(left)
        );
    }
    return dp[left][right][hand];
}

int main(){
    ll n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }
    memset(dp, -1, sizeof(dp[0][0][0]) * 3001 * 3001 * 2);
    cout << calc(0, n, 0) << endl;
    return 0;
}
