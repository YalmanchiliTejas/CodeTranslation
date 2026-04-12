#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <functional>
#include <cstring>

using namespace std;

#define mp make_pair
#define FOR(i, a, b) for(int (i)=a;(i)<(b);++(i))
#define rep(i, n)  FOR(i,0,n)
#define FFOR(i, a, b) for(int (i)=a;(i)>(b);--(i))
#define rrep(i,n) FFOR(i,0,n)
#define vsort(v) sort((v).begin(), (v).end());					//小さい順
#define rvsort(v) sort(v.begin(), v.end(),greater<>());		//大きい順
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define all(c) (c).begin(),(c).end()
#define ll long long
#define lb long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define Print(p) cout<<(p)<<endl
#define F first
#define S second
#define pb push_back
#define mod 1000000007LL
#define INF 123456789012345
#define int ll
typedef pair<int, int> P;
typedef pair<int, P> PP;

const int maxn =1e5 + 10;

//initialization here
//
int cx[105],cy[105],cr[105];
int vx[105],vy[105];
//
//initialization finish


// your function is here
//

//
// your function finished

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	// your code is here
	//

	int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
	int ans = 0;
	if(a + b < c*2) //a,bのみで構築
	{
		ans = a*x + b*y;
	}
	else
	{
		int cc = min(x,y);
		ans = c*cc*2;

		if(x == cc)
		{
			if(b < 2*c)
			{
				ans += b*(y-cc);
			}
			else
			{
				ans += c*(y-cc)*2;
			}
		}
		else
		{
			if(a < 2*c)
			{
				ans += a*(x-cc);
			}
			else
			{
				ans += c*(x-cc)*2;
			}
		}
	}

	Print(ans);
	//
	// your code finished


	return 0;
}