#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define FOR(n) for(int i=0;i<n;i++)
#define till(n) for(int i=1;i<=n;i++)
#define mod 1000000007
using namespace std;

ll a[3000];

pair<ll, ll> dp[3000][3000];

pair<ll, ll> solve(ll i, ll j){
    if(i==j) return make_pair(a[i], 0);
    pair<ll, ll> tmp1, tmp2, ans;

    if(dp[i][j].first != -1 && dp[i][j].second != -1) return dp[i][j];

    tmp1 = solve(i+1, j); tmp1 = make_pair(tmp1.first, tmp1.second + a[i]);
    tmp2 = solve(i, j-1); tmp2 = make_pair(tmp2.first, tmp2.second + a[j]);


    if(tmp1.second> tmp2.second)
        ans = make_pair(tmp1.second, tmp1.first);
    else ans = make_pair(tmp2.second, tmp2.first);

    return dp[i][j] = ans;
}

int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin >> n;

    for(int i=0;i<3000;i++){
        for(int j=0;j<3000;j++){
            dp[i][j] = make_pair(-1, -1);
        }
    }

    for(int i=0;i<n;i++)cin >> a[i];

    pair<ll, ll> ans = solve(0, n-1);

    cout << ans.first - ans.second;

	return 0;
}
