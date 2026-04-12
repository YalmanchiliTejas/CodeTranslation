#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;


int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	long long ans = 0;
	vector<long> v(n);
	long long mod = pow(10, 9) + 7;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	//cout << sum << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << ans << endl;
		sum = (sum - v[i] + mod) % mod;
		ans += (v[i] * sum) % mod;
	}
	cout << ans % mod;
}
