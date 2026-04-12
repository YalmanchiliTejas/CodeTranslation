#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

string s;
int n, k;
ll dp[200][3][5];

ll solve(int idx, bool smaller, int c){
    if(c == k + 1) return 0;
    if(idx == n) return c == k;
    if(~dp[idx][smaller][c]) return dp[idx][smaller][c];
    if(smaller){
        ll op1 = solve(idx + 1, 1, c);
        ll op2 = 9 * solve(idx + 1, 1, c + 1);
        return dp[idx][smaller][c] = op1 + op2;
    }
    else{
        ll ans = 0;
        for(int i = 0; i < 10; i++){
            if(s[idx] - '0' == i){
                ans += solve(idx + 1, 0, c + (i != 0));
                break;
            }
            else ans += solve(idx + 1, 1, c + (i != 0));
        }
        return dp[idx][smaller][idx] = ans;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s >> k;
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0);

    return 0;
}


