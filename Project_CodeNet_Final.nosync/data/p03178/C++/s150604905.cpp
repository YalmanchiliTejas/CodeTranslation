#include<bits/stdc++.h> 
using namespace std; 


const int mod = 1e9 + 7;
int memo[10005][105];

int rec(int n, int su, int rem){
    if(memo[n][su] != -1) return memo[n][su];
    int ans = 0;
    if(not n){
        ans = (su%rem)?0:1;
    }
    else{
        for(int j = 0;j < 10;++j)
            ans = (ans + rec(n - 1, (su + j) % rem, rem)) % mod;
    }
    return memo[n][su] = ans;
}



signed main(){

    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    memset(memo, -1, sizeof(memo));
    

    string l;
    int d, n, curr = 0;
    cin >> l >> d;
    n = l.length();

    int ans = 0;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < l[i] - '0';++j){
            ans = (ans + rec(n - i - 1, (curr + j) % d, d)) % mod;
        }

        curr = (curr + (l[i] - '0')) % d;
    }
    
    ans -= 1;
    if(curr % d == 0) ans += 1;

    cout << (ans + mod) % mod << endl;


}