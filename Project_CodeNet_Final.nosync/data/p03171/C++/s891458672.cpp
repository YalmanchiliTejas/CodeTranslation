#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define int long long int
#define pb push_back
// #define M 1000000007
#define inf 10000000000
#define ff first
#define ss second
#define deb(x) cout< #x< " "< x< endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<=n;i++)
#define FORR(a,b,c) for(int a= b;a>=c;a--)
#define fa(arrr) for(auto x:arrr)
#define iPair pair<int, pair<int,int>>
#define sz size()
// #define mp make_pair
#define mxm3(a,b,c) max(a, max(b,c))
#define mi3(a,b,c) min(a, min(b,c))
#define mxn 500005
#define PII pair<int,int>
#define all(v) v.begin(), v.end()
#define endl "\n"
// #define N 1000
#define C 4
#define nfs ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
// Ordered Set Tree
// typedef tree<PII, null_type, less<PII>,
//         rb_tree_tag,
//         tree_order_statistics_node_update>
//         oset;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

void computeLPSArray(string pat, int M, int* lps);

int dp[3003][3003][2];

int recurr(int *arr, int i, int j, bool turn) {
    if (i > j) return 0;
    if (dp[i][j][turn] != -1) return dp[i][j][turn];

    if (turn == 1) {
        return dp[i][j][turn] = max(arr[i] + recurr(arr, i + 1, j, !turn), arr[j] + recurr(arr, i, j - 1, !turn));
        // return dp[i][j][turn];
    }
    else {
        return dp[i][j][turn] = min(recurr(arr, i + 1, j, !turn), recurr(arr, i, j - 1, !turn));
    }
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int scrx = recurr(arr, 0, n - 1, 1);
    int scry = sum - scrx;
    cout << scrx - scry << endl;
}


int32_t main()
{


    nfs;
    int t;
    // facto();
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

    return 0;
}