#include<bits/stdc++.h>

using namespace std;
#define taskname "TEST"
#define pb	push_back
typedef long double ld;
typedef long long ll;
const int maxn = 3e3 + 5;
int n , a[maxn];
ll dp[maxn][maxn];
const ll inf = 1e18;
ll Cal(int i , int j)
{
    if(i > j)return 0;
    ll & res = dp[i][j];
    if(res != inf)return res;
    int len = j - i + 1;
    if((n - len) % 2 == 0)
    {
        res = -inf;
        res = max(res , Cal(i + 1,j) + a[i]);
        res = max(res , Cal(i , j - 1) + a[j]);
    }
    else
    {
        res = inf;
        res = min(res , Cal(i + 1 , j) - a[i]);
        res = min(res , Cal(i , j - 1) - a[j]);
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(taskname".INP","r"))
        freopen(taskname".INP", "r",stdin) ,
        freopen(taskname".OUT", "w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)cin >> a[i];
    fill_n(&dp[0][0],maxn*maxn,inf);
    cout << Cal(1,n);
}
