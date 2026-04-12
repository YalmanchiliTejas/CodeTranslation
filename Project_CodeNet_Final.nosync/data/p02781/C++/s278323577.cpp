#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef vector <ll> vll;
typedef pair <ll, ll> pll;
#define pb push_back
#define mp make_pair
#define MAX 1000000
#define mod 1000000007
#define all(_) _.begin(), _.end()
#define F first
#define S second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll dp[105][105][2];
ll cal(string &s, ll index, ll num, ll k, bool f)
{
    // cout << index << ' ' << num << ' ' << f << endl;
    if(dp[index][num][f] != -1)
        return dp[index][num][f];
    if(index == s.size())
        return (num == k ? 1 : 0);
    else if(num > k)
        return 0;
    ll ans = 0;
    for(ll i = 0; i < s[index] - '0'; i++)
    {
        if(!i)
            ans += cal(s, index + 1, num, k, true);
        else
            ans += cal(s, index + 1, num + 1, k, true);
    }
    ans += cal(s, index + 1, (num + (s[index] - '0' > 0 ? 1 : 0)), k, f);
    if(f)
    {
        for(ll i = s[index] - '0' + 1; i <= 9; i++)
        {
            if(!i)
                ans += cal(s, index + 1, num, k, true);
            else
                ans += cal(s, index + 1, num + 1, k, true);
        }       
    }
    dp[index][num][f] = ans;
    return ans;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    ll i, k;
    cin >> s >> k;
    memset(dp, -1, sizeof dp);
    cout << cal(s, 0, 0, k, false) << endl;
    return 0;
}