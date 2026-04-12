#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;
int n;
int k;
int memo[100010][2][4];

int dp(int i, int f, int nk){
    if(i == n){
        if(nk == k){
            return 1;
        }else{
            return 0;
        }
    }

    if(memo[i][f][nk] != -1) return memo[i][f][nk];

    int ans = 0;
    int fin = f == 1 ? s[i]-'0' : 9;

        for(int j = 0;j <= fin;j++){
            if(j == 0){
                ans += dp(i+1, f == 1 && j == fin, nk); 
            }else{
                if(nk < k){
                    ans += dp(i+1, f == 1 && j == fin, nk+1); 
                }

            }
        }

    return memo[i][f][nk] = ans;
}


signed main(){
    cin >> s;
    cin >> k;
    n = s.size(); 
    memset(memo, -1, sizeof(memo));

    cout << dp(0, 1, 0) << endl;

    return 0;
}

