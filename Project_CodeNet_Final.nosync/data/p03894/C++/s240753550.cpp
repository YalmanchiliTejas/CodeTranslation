#include <iostream>
#include <vector>
#define For(i, n) for(int i = 0; i < (n); i ++)

using namespace std;

int main(void){
    int n, q;
    cin >> n >> q;

    vector<int> dp(n+1);
    int pos = 1;
    dp[2] = 1;

    For(i, q){
        int a, b;
        cin >> a >> b;
        
        if(pos == a) pos = b;
        else if(pos == b) pos = a;
        swap(dp[a], dp[b]);
        
        if(pos-1 >= 1) dp[pos-1] = 1;
        if(pos+1 <= n) dp[pos+1] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) if(dp[i] || i == pos) ans ++;
    cout << ans << "\n";
}
