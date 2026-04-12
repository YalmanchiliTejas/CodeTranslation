#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int INF = 1000000007;
const ll INFLL = 1000000000000000007;

#define st first
#define nd second
#define pb push_back
#define _boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ***************************** CODE ***************************** //

const int MAX = 3e3 + 7;

ll tab[MAX];
ll w[MAX][MAX];
ll dp[MAX][MAX];

ll calc(int l, int r)
{
    if(w[l][r])
        return dp[l][r];
    w[l][r] = true;

    if(l == r)
    {
        dp[l][r] = tab[l];
        return dp[l][r];
    }

    dp[l][r] = max(tab[l] - calc(l+1, r), tab[r] - calc(l, r-1));
    return dp[l][r];
}

int main() {
    _boost;

    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tab[i];

    cout << calc(0, n-1);

    return 0;
}
