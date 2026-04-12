    #include<bits/stdc++.h>
    using namespace std;
    # define LL long long
    # define int long long
    #define gok ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    # define mo 998244353
    # define pi acos(-1)
    //vector<pair<int,int>> v;
    //int x0=INT_MAX,y0=INT_MAX;
    /*int crossprod(pair<int,int> a,pair<int,int> b,pair<int,int> c)
    {
        int x1 = a.first-b.first;
        int x2 = a.first-c.first;
        int y1 = a.second-b.second;
        int y2 = a.second-c.second;
        return x1*y2 - y1*x2;
    }
    int direction(pair<int,int> a,pair<int,int> b,pair<int,int> c) {
       int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
       if (val == 0)
          return 0;     //colinear
       else if(val < 0)
          return 2;    //anti-clockwise direction
          return 1;    //clockwise direction
    }*/
   const int N = 3005;
const int MOD = 998244353;

int n, s;
int a[N], cache[N][N];

int dp(int idx, int s)
{
	if(s == 0)
		return (n - idx + 2);
	if(s < 0)
		return 0;
	if(idx > n)
		return 0;
	int &ans = cache[idx][s];
	if(ans != -1)
		return ans;
	ans = dp(idx + 1, s) + dp(idx + 1, s - a[idx]);
	ans %= MOD;
	return ans;
}

signed main()
{
//	IOS;
gok
	memset(cache, -1, sizeof(cache));
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	dp(1,s);
	for(int i = 1; i <= n; i++){
		//ans += dp(i, s);
	  ans += cache[i][s];
	}
	ans %= MOD;
	cout << ans;
	return 0;
}
