#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<deque>

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e8;

using namespace std;

#define vvint(vec,n,m,l) vector<vector<int>> vec(n,vector<int>(m,l));
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>;
#define pint pair<int,int>;
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> h(n);
	int ans = 0;
	rep(i, n)
	{
		cin >> h[i];
		rep(j, i)
		{
			if (h[i] < h[j])
			{
				break;
			}
			if (j + 1 == i)
			{
				ans++;
			}
		}
	}

	cout << ans + 1 << endl;

	debug;

}