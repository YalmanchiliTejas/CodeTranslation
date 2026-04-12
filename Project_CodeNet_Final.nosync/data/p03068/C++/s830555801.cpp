#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<string>
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e8;
using namespace std;

#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;

	char tmp = s[k - 1];


	for (int i = 0;i < n;i++)
	{
		if (tmp == s[i])
		{
			continue;
		}
		else
		{
			s[i] = '*';
		}
	}

	cout << s << endl;

}