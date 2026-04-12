#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

#define        MX        3005

int ara[MX];
ll dp[MX][MX][2];

void solve(int l, int r, bool who)
{
    if(l > r){
        dp[l][r][who] = 0;
        return;
    }
    ll &res = dp[l][r][who];

    if(res != -1) return;


    solve(l+1, r, !who);
    solve(l, r-1, !who);

    if(who) res = max(ara[l]+dp[l+1][r][!who], ara[r]+dp[l][r-1][!who]);
    else res = min(dp[l+1][r][!who]-ara[l], dp[l][r-1][!who]-ara[r]);

}

int main()
{
    optimize
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>ara[i];
    }

    RESET(dp, -1);
    solve(0, n-1, 1);

    cout<<dp[0][n-1][1]<<endl;
}
