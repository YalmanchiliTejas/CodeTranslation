#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

vector<ll> leg(100, 0), acc(100, 0);
ll one[6] = {0, 0, 1, 2, 3, 3};

ll dfs(ll x, ll i){
    if(i == 1) return one[x];
    if(x == 1) return 0;
    if(x == 2 + leg[i-1]) return acc[i-1] + 1;
    if(x == 3 + 2 * leg[i-1]) return  2*acc[i-1] + 1;
    if(x < 2 + leg[i-1]) return dfs(x-1, i-1);
    if(x > 2 + leg[i-1]) return dfs(x-leg[i-1]-2, i-1) + acc[i-1] + 1;
}

int main(){
    ll N, X;
    cin >> N >> X;
    acc[1] = 3;
    leg[1] = 5;
    rep(i, 2, N+1){
        leg[i] = 3 + 2 * leg[i-1];
        acc[i] = 1 + 2 * acc[i-1];
    }
    cout << dfs(X, N) << endl;
    return 0;
}