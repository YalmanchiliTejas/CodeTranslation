 
//It doesn't matter how slow you go, Unless you don't stop.
#include<iostream>
#include<algorithm>
#include<bitset>
 
#include<cmath>
#include<cstring>
#include<climits>
 
#include<deque>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
 
#include<fstream>
#include<chrono>
using namespace std;
 
typedef long long LL;
typedef pair<LL,LL> p64;
typedef vector<LL> v64;
typedef map<LL,LL> mp64;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,s,e) for(long long i=s;i<=e;i++)
#define brep(i,s,e) for(long long i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define DANGER std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 2e5 + 5;
LL dp[N][2];
void solve()
{
     int n;
	cin >> n;
	v64 arr(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];
	memset(dp, 0, sizeof(dp));
	dp[2][1] = arr[2];
	dp[2][0] = arr[1];
	for (int i = 3; i < n + 1; i++)
	{
		if (i & 1)
		{
			LL temp = max({dp[i - 3][1], dp[i - 3][0], dp[i - 2][1], dp[i - 2][0]});
			dp[i][1] = arr[i] + temp;
			dp[i][0] = max({arr[i - 1] + dp[i - 2][0], arr[i - 1] + dp[i - 3][1], arr[i - 1] + dp[i - 3][0], arr[i - 2] + dp[i - 3][0]});
		}
		else
		{
			dp[i][1] = arr[i] + max({dp[i - 2][1], dp[i - 2][0], dp[i - 1][0]});
			dp[i][0] = arr[i - 1] + dp[i - 2][0];
		}
	}
	cout << max(dp[n][1], dp[n][0]) << endl;
	return;
}
 
int main()
{
    DANGER;
    ofstream out("output.txt");
 
    auto start = chrono::high_resolution_clock::now();
    
    LL t = 1;
    // cin>>t;
    rep(test,1,t)
    {
        solve();
    }
    
    auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); 
    // cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
}