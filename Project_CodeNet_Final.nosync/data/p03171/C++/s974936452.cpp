#include<bits/stdc++.h>
using namespace std;
 
#define int long long
typedef long long ll;  
typedef vector<ll> vi; 
typedef pair<int, int> ii; 
typedef vector<ii> vii; 
typedef vector<vi> vvi;
#define F first
#define S second
#define pb emplace_back
#define M 1000000007
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,a,b) for(int i = a; i<= b; i++)
#define ws " "
#define all(c) c.begin(), c.end()
#define ln "\n" 
 
void printarray(int ar[], int n) {
    for (int i = 0; i < n; i++) {
        cout << ar[i] << ws;
    }
    cout << ln;
}

int memo[3001][3001];
int ar[3001], sum[3001] = {0};

int dp(int start, int end) {
    if (start > end) {
        return 0;
    }
    int ans = 0;
    if (memo[start][end] != 0) {
        return memo[start][end];
    }
    ans = sum[end] - sum[start - 1];
    ans -= min(dp(start + 1, end), dp(start, end - 1));
    memo[start][end] = ans;
    return ans;
}

void init() {
    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 3000; j++) {
            memo[i][j] = 0;
        }
    }
}

main() {
    IOS;
    int n;
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        sum[i] = sum[i - 1] + ar[i];
    }
    cout << dp(1,n) - min(dp(1, n -1), dp(2, n));

}
 
/*  Check for base cases such as n == 1
    and cases like it where code can fail */