#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[110][5];

int main(){
    dp[0][0] = 1;
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= 105; i++){
        dp[i][0] = 1;
        for(int j = 1; j < 5; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    string s; cin >> s;
    int k; cin >> k;
    int sz = s.size(), s_top = s[0] - '0';
    ll ans = 0;
    for(int i = k; i < sz; i++){
        ans += pow(9,k)*dp[i-1][k-1];
    }
    ans += (s_top-1)*pow(9,k-1)*dp[sz-1][k-1];
    if(k == 1) ans++;
    else if(k == 2){
        int cnt, num;
        bool ok = false;
        for(int i = 1; i < sz; i++){
            if(s[i] != '0'){
                cnt = i+1;
                num = s[i] - '0';
                ok = true;
                break;
            }
        }
        if(ok) ans += num + 9*(sz - cnt);
    }
    else{
        int cnt1 = 0, num1 = 0, cnt2 = 0, num2 = 0;
        bool ok1 = false, ok2 = false;;
        for(int i = 1; i < sz; i++){
            if(s[i] != '0' && cnt1 != 0){
                cnt2 = i+1;
                num2 = s[i] - '0';
                ok2 = true;
                break;
            }
            if(s[i] != '0' && cnt1 == 0){
                cnt1 = i+1;
                num1 = s[i] - '0';
                ok1 = true;
            }
        }
        if(ok1) ans += 9*(sz - cnt1)*(num1-1) + dp[sz - cnt1][2]*9*9; //位置cnt1が1~(num1-1)の場合 + 位置cnt1が0の場合
        if(ok2) ans += num2 + 9*(sz - cnt2); //位置cnt1はnum1の時、 位置cnt2が1~(num2-1)の場合 + 位置cnt2が0の場合
    }
    cout << ans << endl;
}