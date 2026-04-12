#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007

ll digitSum(string &k, int s){

    int n = k.size();
    if(n == 1){
        int ans = 0;
        for(int i=1; i<=k[0]-'0'; i++)
            if(i%s == 0)
                ans++;
        return ans;
    }
    vector<vector<ll>> dp(n, vector<ll>(s, 0));
    // dp[i][j] stores the number of integers having 'i' digits and
    // having remainder as 'j' when sum of digits is divided by 's'

    for(int d=1; d<=9; d++){
        int rem = d%s;
        dp[1][rem]++;
    }

    dp[0][0] = 1;
    for(int i=2; i<=n-1; i++){
        for(int j=0; j<s; j++){
            // Find number of integers having number of digits as 'i'
            // and remainder as 'j'
            // At this place we can append any of the 10 digits
            for(int d=0; d<=9; d++){
                ll req = ((j-d)%s+s)%s;
                dp[i][j] = (dp[i][j] + dp[i-1][req])%M;
            }
        }
    }

    // Now find number of required integers with exactly 'n' digits
    ll ans = 0, sum = 0;
    vector<ll> cnt(s, 0);
    for(int i=0; i<=n-1; i++)
        for(int j=0; j<s; j++)
            cnt[j] = (cnt[j] + dp[i][j])%M;

    for(int i=0; i<n; i++){
        int d = k[i]-'0';
        int st = 0;
        if(i == 0)
            st++;
        for(int w=st; w<d; w++){
            int newSum = sum + w;
            int req = (-newSum%s + s)%s;
            ans = (ans + cnt[req])%M;
        }
        for(int j=0; j<s; j++)
            cnt[j] = ((cnt[j] - dp[n-i-1][j])%M + M)%M;

        sum += d;
    }
    // If the number 'k' itself has sum of digits as multiple of 's'
    if(sum%s == 0)
        ans = (ans + 1)%M;

    for(int i=1; i<=n-1; i++)
        ans = (ans + dp[i][0])%M;

    return ans;
}

int main()
{
 string k;
 cin>>k;
 int s;
 cin>>s;
 ll ans = digitSum(k, s);
 cout<<ans;
 return 0;
}

