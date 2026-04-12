#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll MAX = 100100;
const double PI = 3.1415926;

#define vll vector<ll>
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define all(container) container.begin(), container.end()
#define pll pair<ll,ll>
// #define traverse( container, it) for( typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
ll n;
ll arr[3003];
pll dp[3003][3003][2];

pll fill(ll ptr1, ll ptr2, bool t)
{
	if (ptr1 > ptr2)
		return make_pair((ll)0,(ll)0);
	if (dp[ptr1][ptr2][t] != make_pair((ll)-1,(ll)-1))
		return dp[ptr1][ptr2][t];
	// cout << ptr1 << " " << ptr2 << " " << t << endl; 
	pll fi = fill(ptr1 + 1, ptr2, !t);
	pll se = fill(ptr1, ptr2 - 1, !t);

	if (!t)
	{
		fi.first += arr[ptr1];
		se.first += arr[ptr2];
		if (fi.first - fi.second > se.first - se.second)
			dp[ptr1][ptr2][t] = fi;
		else
			dp[ptr1][ptr2][t] = se;
		return dp[ptr1][ptr2][t];
	}
	else
	{
		fi.second += arr[ptr1];
		se.second += arr[ptr2];
		if (fi.first - fi.second <= se.first - se.second)
			dp[ptr1][ptr2][t] = fi;
		else
			dp[ptr1][ptr2][t] = se;
		return dp[ptr1][ptr2][t];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for(int i = 0; i < 3003; i++)
		for(int j = 0; j < 3003; j++)
			for(int h = 0; h < 2; h++)
				dp[i][j][h] = make_pair(-1,-1);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	pll c = fill(0,n-1,0);
	cout << c.first - c.second << endl;
	return 0;
}