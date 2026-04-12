#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n,x,m;
    cin >> n >> x >> m;
    vector<vector<ll>> sum(40,vector<ll>(m));
    vector<vector<ll>> doubling(40,vector<ll>(m));

    for(ll i = 0; i < m; i++){
        sum[0][i] = i;
        doubling[0][i] = i*i%m;
    }

    for(int i = 0; i < 40-1; i++){
        for(int j = 0; j < m; j++){
            doubling[i+1][j] = doubling[i][doubling[i][j]];
            sum[i+1][j] = sum[i][j]+sum[i][doubling[i][j]];
        }
    }

    ll now = x, ans = 0;
    for(ll i = 40-1; i >= 0; i--){
        if(n >> i & 1){
            ans += sum[i][now];
            now = doubling[i][now];
        }
    }

    cout << ans << endl;
    
    return 0;
}