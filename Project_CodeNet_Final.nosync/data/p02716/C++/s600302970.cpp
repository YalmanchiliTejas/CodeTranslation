#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<vector>

using namespace std;

#define long long long
#define ft(i, a, b) for (int i = (long)a ; i <= (long)b ; i++)
#define fd(i, a, b) for (int i = (long)a ; i >= (long)b ; i--)

const int mxN = 2e5 + 5;
const long oo = 1e15;

long n , ans;
long a[mxN] , dp[mxN] , pre[mxN];

void Solve() {
    pre[1] = a[1];
    for(int i = 3; i <= n; i+= 2) {
        pre[i] = pre[i - 2] + a[i];
    }
    /*ft(i , 1 , n) if (i % 2 == 1) cout << pre[i] << " ";
    else cout << "  ";
    cout << "\n";*/
    dp[1] = 0;
    dp[2] = max(a[1] , a[2]);
    ft(i , 3 , n) {
        if (i % 2 == 1) {
            dp[i] = max(dp[i - 1] , dp[i - 2] + a[i]);
        }
        else dp[i] = max(pre[i - 1] , dp[i - 2] + a[i]);
    }
    //ft(i , 1 , n) cout << dp[i] << " ";
    cout << dp[n];
}

void FastInput() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
}

void Input() {
    cin >> n;
    ft(i , 1 , n) cin >> a[i];
}

int main() {
    FastInput();
    Input();
    Solve();
}