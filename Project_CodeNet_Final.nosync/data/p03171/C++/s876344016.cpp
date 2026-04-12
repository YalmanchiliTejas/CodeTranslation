#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define sz(v) (v).size()
#define debug(x) cerr << #x << "_=_" << x << "\n";
#define sum(n) ((n)*((n)+1)>>1)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;

const int MAXN = 3e3+5;
ll dp[MAXN][MAXN], a[MAXN];
int n;

ll f(int i, int j){
    if(i==j) return a[i];
    if(~dp[i][j]) return dp[i][j];
    return dp[i][j] = max(a[i] - f(i+1, j), a[j] - f(i, j-1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof dp);

    cout << f(0, n-1) << "\n";




    return 0;
}

/*
1
9 3
111100000
 */