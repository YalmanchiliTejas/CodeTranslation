#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB emplace_back

using namespace std;

const int N = 1e6+100;

long long int dp[N], a[N], mod=998244353;

long long int wop(long long int x, long long int y) {
    long long int ret=1;
    for(;y>=1;y/=2) {
        if(y&1)ret*=x;
        x*=x;
    }
    return ret;
}

bool PA(string s) {
    for(int i = 0 ; i < s.size() ; i++ ) {
        if(s[i]!=s[s.size()-i-1])return 0;
    }
    return 1;
}

int main () {
    ios::sync_with_stdio(0);
    long long int n, s, ans=0;
    cin >> n >> s;
    for(int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        if(i==0) {
            dp[0]=dp[a[i]]=1;
        }
        else {
            for(int j = s ; j >= a[i] ; j-- ) {
                dp[j]+=dp[j-a[i]];
                dp[j]%=mod;
            }
            dp[0]++;
            dp[a[i]]++;
            dp[0]%=mod;
            dp[a[i]]%=mod;
        }
        ans+=dp[s];
        ans%=mod;
    }
    cout << ans;
}
