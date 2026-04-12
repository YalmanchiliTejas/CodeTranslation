#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB emplace_back

using namespace std;

const int N = 1e5+100, D = 110;

long long int dp[N][D], mod = 1e9+7, d, pr[N];

int ok2(int x) {
    x%=mod;
    x+=mod;
    return x%mod;
}

int ok(int x) {
    x%=d;
    x+=d;
    return x%d;
}

int main () {
    string s;
    cin >> s;
    cin >> d;
    dp[0][0]=1;
    for(int i = 1 ; i <= s.size() ; i++ ) {
        for(int j = 0 ; j < d ; j++ ) {
            for(int k = 0 ; k < 10 ; k++ ) {
                dp[i][j]+=dp[i-1][ok(j-k)];
                dp[i][j]%=mod;
            }
        }
    }
    reverse(s.begin(),s.end());
    long long int car=0, ans=0;
    for(int i = s.size()-1 ; i >= 0 ; i--) {
        for(int j = 0 ; j < s[i]-'0' ; j++) {
            ans+=dp[i][ok(d-j-car)];
            ans%=mod;
        }
        car+=s[i]-'0';
        car%=mod;
    }
    cout << ok2(ans-1+(car%d==0));
}
