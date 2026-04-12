#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

void solve() {

    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    vector<vector<ar<ll,2>>> dp(n+1,vector<ar<ll,2>>(n+1,{0,0}));

    // dp[i][j][0] = for elements from i - j max score for first person picking
    // dp[i][j][1] = for elements from i - j max score for second person picking

    for(int i = n-1;i >=0;i--){
        for(int j = i;j < n;j++){
            if(i == j){
                dp[i][j] = {a[i],0};
            }else{
                ar<ll,2> op1 = {a[i]+dp[i+1][j][1], dp[i+1][j][0]};
                ar<ll,2> op2 = {a[j]+dp[i][j-1][1], dp[i][j-1][0]};
                dp[i][j] = max(op1,op2);
            }
        }
    }

    cout << dp[0][n-1][0] - dp[0][n-1][1] << endl;

}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
