#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define ff first
#define ss second
#define pb push_back
#define ld long double
constexpr int MAXN = 3000;

int N;
ll a[MAXN+5], DP[2][MAXN+5][MAXN+5];

ll f(int p, int l, int r){
    if(l > r) return 0;
    if(DP[p][l][r] != LLONG_MAX)
        return DP[p][l][r];
    if(p){
        return DP[p][l][r] = max(f(0, l+1, r) + a[l], f(0, l, r-1) + a[r]);
    } else{
        return DP[p][l][r] = min(f(1, l+1, r) - a[l], f(1, l, r-1) - a[r]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++)
            DP[0][i][j] = DP[1][i][j] = LLONG_MAX;
    }
    cout << f(1, 0, N-1);
}