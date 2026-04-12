#include<bits/stdc++.h>

#define int long long int
#define mp make_pair
#define mod 1000000007
using namespace std;

string s;
int d , n;
vector <int> v(10002);
int dp[10002][102][2];

int fun(int pos , int rem , int limit)
{
    if(pos == n){
        return (rem == 0);
    }
    int &ans = dp[pos][rem][limit];
    if(ans != -1){
        return ans;
    }
    ans = 0 ;
    if(limit){
        for (int i = 0; i <= v[pos]; ++i) {
            if(i == v[pos]){
                ans += fun(pos+1,(rem+i)%d,1);
            }
            else{
                ans += fun(pos+1,(rem+i)%d,0);
            }
        }
    }
    else{
        for (int i = 0; i <= 9; ++i) {
            ans += fun(pos+1,(rem+i)%d,0);
        }
    }
    ans %= mod;
    return ans;
}

int32_t main() {
    string s;
    cin >> s;
    scanf("%lld", &d);
    n = s.length();
    for (int i = 0; i < n; ++i) {
        v[i] = s[i] - '0';
    }
    for (int i = 0; i < 10002; ++i) {
        for (int j = 0; j < 102; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= v[0]; ++i) {
        if(i == v[0]){
            ans += fun(1,i%d,1);
        }
        else{
            ans += fun(1,i%d,0);
        }
    }
    ans = (ans-1+mod)%mod;
    printf("%lld",ans);
    return 0;
}