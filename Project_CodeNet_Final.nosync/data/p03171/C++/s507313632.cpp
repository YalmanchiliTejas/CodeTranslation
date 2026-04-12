#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll dp[3002][3002];
ll a[3002];
int n;

void search(int start, int delta){
    int end = start + delta;
    int turn = 1;
    if((n - delta) % 2 == 0) turn = -1;
    ll now1 = dp[start + 1][end] + turn * a[start];
    ll now2 = dp[start][end - 1] + turn * a[end];
    if(turn == 1){
        dp[start][end] = max(now1, now2);
    } else {
        dp[start][end] = min(now1, now2);
    }
}

int main() {
    //cout.precision(10);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int delta = 0; delta < n; delta++){
        for(int start = 1; start + delta <= n; start++){
            search(start, delta);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[1][n] << endl;
    return 0;
}
