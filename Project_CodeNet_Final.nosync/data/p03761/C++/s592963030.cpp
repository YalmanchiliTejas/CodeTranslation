#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using str = string;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
const double PI = 3.141592653589793238;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define REP(i, m, n) for (int i = m; i < (int)n; i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greator<>()
#define d20 std::setprecision(20)
#define veci vector<int>
#define vecll vector<long long int>
#define vecd vector<double>
template <typename T>
T lcm(T a, T b)
{
	return a / __gcd(a, b) * b;
}
void comb(vector<vector<long long int>> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (int k = 1; k < v.size(); k++)
	{
		for (int j = 1; j < k; j++)
		{
			v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
		}
	}
}
bool is_not_out_of_range(size_t now, size_t max_num)
{
	return !(now < 0 || max_num <= now);
}
int main()
{
	int n;
	cin >> n;
	vector<map<char, int>> v(n);
	rep(i, n)
	{
		str tmp;
		cin >> tmp;
		rep(j, tmp.size())
		{
			v[i][tmp.at(j)]++;
		}
	}
	str ans = "";
	for (char a = 'a'; a <= 'z';)
	{
		bool is_push_back = true;
		rep(i, n)
		{
			if (v[i][a] == 0)
			{
				is_push_back = false;
				a++;
				break;
			}
			else
			{
				v[i][a]--;
			}
		}
		if (is_push_back)
		{
			ans.push_back(a);
		}
	}
	cout << ans << endl;
	return 0;
}