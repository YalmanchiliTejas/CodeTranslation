#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()

ll stoneGame(vector<ll>& piles) {
	//cout << piles[0] << " ";
    ll n = piles.size();
    vector <vector<ll> > dp(n, vector <ll>(n,0));
    for (int i = 0;i < n;i++)
        dp[i][i] = piles[i];
    for (int d = 1; d < n; d++)
    {
        for (int i = 0;i < n-d;i++)
        {
            dp[i][i+d] = max(piles[i]-dp[i+1][i+d], piles[i+d] - dp[i][i+d-1]);
        }
    }
    return dp[0][n-1];
}


int main()
{
    int n;
    cin >> n;
    std::vector<ll> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin >> v[i];
    }
    cout << stoneGame(v) << "\n";

	return 0;
}
