//******* It's LEVI_17 ***************

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ff first
#define ss second
#define MP make_pair
#define mset(x,a) memset(x,a,sizeof(x))
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define sqr(a) (a)*(a)
#define all(x) (x).begin(), (x).end()
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define vvll vector<vector<ll>>  
#define vll vector<ll> 
#define pll pair<ll,ll>
#define vpll vector<pll>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define cases ll t;cin >> t;while(t--)
#define rr return 0
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define deb(a)			std::cerr<<#a<<"="<<(a)<<"\n"
#define deb2(a,b)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define deb3(a,b,c)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
const int MOD = 1000 * 1000 * 1000 + 7;

//syntax for priority queue
// max queue -> priority_queue<ll>
// min queue -> priority_queue<ll,vector<ll>,greater<ll>>

//##############################################################################################

//double getRes(double arr[],ll n)
//{
//    ll ones = 0, twos = 0, threes = 0;
//    f(i, n)
//    {
//        if (arr[i] == 1)
//            ones++;
//        if (arr[i] == 2)
//            twos++;
//        if (arr[i] == 3)
//            threes++;
//    }
//    ll maxones = ones + twos + threes;
//    ll maxtwos = twos + threes;
//    ll maxthrees = threes;
//    double dp[n+1][n+1][n+1];
//    memset(dp, 0, sizeof(dp));
//    ll i=0, j=0, k=0;
//    for ( k = 0; k <= maxthrees; k++)
//    {
//        for ( j = 0; j<=maxtwos-k; j++)
//        {
//            for ( i = 0; i <=maxones-j-k; i++)
//            {
//                if (i + j + k == 0)
//                    continue;
//                else
//                {
//                    dp[i][j][k] = ((double)n /(double) (i + j + k));
//                    if (i > 0)
//                        dp[i][j][k] += (dp[i - 1][j][k] * i) / (i + j + k);
//                    if (j > 0)
//                        dp[i][j][k] += (dp[i + 1][j-1][k] * j) / (i + j + k);
//                    if (k > 0)
//                        dp[i][j][k] += (dp[i][j+1][k-1] * k) / (i + j + k);
//
//                }
//            }
//        }
//    }
//
//    return dp[ones][twos][threes];
//}

const int nax = 3005;
ll dp[nax][nax];

void solve()
{
    ll n;
    cin >> n ;
    vll arr(n);
    f(i, n)
    {
        cin >> arr[i];
    }
    
    for (ll L = n - 1; L >= 0; L--)
    {
        for (ll R = L; R < n; R++)
        {
            if (L == R)
                dp[L][R] = arr[L];
            else
                dp[L][R] = max(arr[L] - dp[L + 1][R], arr[R] - dp[L][R - 1]);
        }
    }

    cout << dp[0][n - 1] << "\n";
}

//###############################################################################################

int main()
{
    fast;
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    rr;
}


//Watashi wa tsuyoku modotte kimasu