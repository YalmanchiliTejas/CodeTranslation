
#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[5555];
int cache[5555][5555];
void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int solve(int start,int end)
{
	if(start > end)
	{
		return 0;
	}
	if(start == end)
	{
		return a[start];
	}
	if(cache[start][end] != -1)
	{
		return cache[start][end];
	}
	return cache[start][end] = max(a[start] + min(solve(start+2,end),solve(start+1,end-1)),a[end] + min(solve(start,end-2),solve(start+1,end-1)));
}
int32_t main()
{
  //c_p_c();
  memset(cache,-1,sizeof(cache));
  int n,ts = 0;
  cin >> n;
  for(int i=0;i<n;i++)
  {
  	cin >> a[i];
  	ts+=a[i];
  }
  int x = solve(0,n-1);
  int y = ts - x;
  cout<<x-y<<endl;
  return 0;
}

