#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll a[51]; // レベル i のバーガーの層の総数
ll p[51]; // レベル i のバーガーに含まれるパティの総数

// レベル n のバーガー下から x 層に含まれるパティの個数
ll solve(ll n, ll x){
    if(n == 0){
        if(x <= 0) return 0;
        else return 1;
    }
    if(x == 1) return 0;
    if(x <= 1 + a[n-1]) return solve(n-1, x-1);
    if(x == 2 + a[n-1]) return p[n-1] + 1;
    if(x <= 2 + 2 * a[n-1]) return p[n-1] + 1 + solve(n-1, x-1-a[n-1]-1);
    if(x == 3 + 2 * a[n-1]) return 2 * p[n-1] + 1; 
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, x; cin >> n >> x;
    a[0] = 1;
    p[0] = 1;
    for(int i=1;i<=n;i++){
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }
    cout << solve(n, x) << endl;
}