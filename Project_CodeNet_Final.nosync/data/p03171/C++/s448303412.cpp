#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, temp,t, j, b, n, X, Y, dp[3005][3005];
vector<ll>V;
bool vis[3005][3005];
ll solve(int l, int r)
{
    if(l>r)
        return 0;
    if(vis[l][r])
        return dp[l][r];

    ll score1 = V[l]-solve(l+1,r);
    ll score2 = V[r]-solve(l,r-1);
    vis[l][r] = true;
    return dp[l][r] = max(score1, score2);
}
int main()
{
    //I am Monim, a tiny creature of Allah
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> temp;
        V.push_back(temp);
    }
    cout << solve(0,n-1) << endl;
    return 0;
}

