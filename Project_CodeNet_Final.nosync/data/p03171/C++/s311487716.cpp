#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

ll INF = 1ll<<60;
vvll dp(3001, vll(3001, INF));

ll rdp(ll a, ll b, const vll &A){
    if(a == b){
        return dp[a][b] = A[a];
    }
    if(dp[a][b] < INF){
        return dp[a][b];
    }
    return dp[a][b] = max(A[a] - rdp(a+1, b, A), A[b] - rdp(a, b-1, A));
}

int main(){
    ll N; cin >> N;
    vll a(N);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    rdp(0, N-1, a);
    cout << dp[0][N-1];
}