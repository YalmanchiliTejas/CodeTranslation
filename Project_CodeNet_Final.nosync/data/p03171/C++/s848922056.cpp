#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<ll> a;
const int MAX_N = 3010;
ll dp[MAX_N][MAX_N]; //  dp[l][r] := [l, r)で最適に行動した時の先手 - 後手
bool used[MAX_N][MAX_N];

ll rec(int l, int r){
    if(r - l == 1) return dp[l][r] = a[l];
    if(used[l][r]) return dp[l][r];
    
    used[l][r] = true;

    return dp[l][r] = max( a[r-1] - rec(l, r-1), a[l] - rec(l+1, r));

}

int main(){
    cin >> N;
    a.resize(N);
    for(int i = 0 ; i < N; i++) cin >> a[i];

    cout << rec(0, N) << endl;
}