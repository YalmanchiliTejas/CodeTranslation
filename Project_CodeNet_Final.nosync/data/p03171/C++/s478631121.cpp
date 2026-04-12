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

const int MX = 3e3+5;

ll dp[MX][MX];
ll ara[MX];

int main()
{
    optimize
    int n;
    cin>>n;

    for(int i = 0; i < n; i++) cin>>ara[i];

    for(int L = n-1; L >= 0; L--){
        for(int R = L; R < n; R++){
            if(L == R){
                dp[L][R] = ara[L];
            }
            else{
                dp[L][R] = max(ara[L]-dp[L+1][R], ara[R]-dp[L][R-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}
