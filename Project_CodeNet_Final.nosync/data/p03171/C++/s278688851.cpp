/*input
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
*/
#include <bits/stdc++.h>  
#define fastIo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)  
#define all(v) (v).begin(), (v).end()  
#define rall(v) (v).rbegin(), (v).rend()  
#define fi first  
#define se second  
#define sz size  
#define pb push_back  
#define mp make_pair  
using namespace std;  
  
//#define LOCAL  
#ifdef LOCAL  
    #define DEBUG(x) do { cout << #x << ": " << x << '\n'; } while (0)  
#else  
    #define DEBUG(x)   
#endif  
  
const double EPS = 1e-9;  
const double PI = 3.141592653589793238462;  
 
typedef long long ll;
ll arr[3005], dp[3005][3005];  
  
ll solve(int st, int end){  
    if(st > end) return 0;  
    if(dp[st][end] != -1) return dp[st][end];  
    ll a = arr[st] + min(solve(st + 2, end), solve(st + 1, end - 1));  
    ll b = arr[end] + min(solve(st + 1, end - 1), solve(st, end - 2));  
    return dp[st][end] = max(a, b);  
}  
  
int main(){  
    fastIo;  
      
    int n;  
    cin >> n;  
  
    ll sum = 0;  
    for(int i = 0; i < n; i++){   
        cin >> arr[i];  
        sum += arr[i];  
    }  
  	memset(dp, -1LL, sizeof(dp));
    cout << 2 * solve(0, n - 1) - sum << '\n';  
      
  
    return 0;  
} 