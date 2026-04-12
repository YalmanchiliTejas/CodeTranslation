#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
string s;
ll d, dp[10001][2][100];
int main() {
    cin>>s>>d;
    int n = s.size();
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
    for(int i = n - 1; i >= 0 ; i--) {
        for(int tight=0;tight<=1;tight++) {
            for(int sum=0;sum<d;sum++) {
                if(tight) {
                    for(int dig = 0; dig <= s[i] - '0' ; dig++) {
                        ll new_sum = sum - dig;
                        while(new_sum < 0)
                            new_sum += d;
                        //cout<<i<<" "<<1<<" "<<sum<<" "<<dig<<" "<<new_sum<<" "<<((dig == s[i] - '0') ? dp[i+1][1][new_sum] : dp[i+1][0][new_sum])<<endl;
                        dp[i][1][sum] += (dig == s[i] - '0') ? dp[i+1][1][new_sum] : dp[i+1][0][new_sum];
                        dp[i][1][sum] %= mod;
                    }
                }
                else {
                    for(int dig = 0; dig < 10 ; dig++) {
                        ll new_sum = sum - dig;
                        while(new_sum < 0)
                            new_sum += d;
                        //cout<<i<<" "<<0<<" "<<sum<<" "<<dig<<" "<<new_sum<<" "<<dp[i+1][0][new_sum]<<endl;
                        dp[i][0][sum] += dp[i+1][0][new_sum];
                        dp[i][0][sum] %= mod;
                    }
                }
            }
        }
    }
    cout<<((dp[0][1][0] > 0) ? (dp[0][1][0] - 1) : (mod - 1));
}
