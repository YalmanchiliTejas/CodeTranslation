#include <bits/stdc++.h>
using namespace std;
#define int long long
const int SIZE = 3030;


int dp[SIZE][SIZE];
int tab[SIZE];
int n;

    void input(){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> tab[i];
    }

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    for(int i = n - 1; i >= 0; i--){
        for(int k = i; k < n; k++){
            if(i == k) dp[i][k] = tab[i];
            else dp[i][k] = max(tab[i] - dp[i + 1][k], tab[k] - dp[i][k - 1]);
        }
    }
    cout << dp[0][n - 1];
    return 0;
}