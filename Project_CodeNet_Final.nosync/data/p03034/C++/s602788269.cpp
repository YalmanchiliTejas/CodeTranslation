#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll s[100001];

int main()
{
	int N;
	cin >> N;
	for (auto i = 0; i < N; ++i)
	{
		cin >> s[i];
	}

	map<ll, vector<ll>> m;

	auto result = 0ll;
	for (auto A = 2; A < N - 1; ++A)
	{
		auto remain = N - A - 1;
		for (auto d = 1; d * d <= remain && (d < A); ++d)
		{
			if ((remain % d) != 0)
			{
				continue;
			}

			for (auto d2 = d, i = 0; i < 2; d2 = remain / d, ++i)
			{
				if (d2 >= A)
				{
					continue;
				}

				auto B = A - d2;
				if ((B % d2 == 0) && (remain / d2) > (B / d2))
				{
					continue;
				}

				auto key = d2 * (ll)N;
				if (m.count(key) == 0)
				{
					auto& tempS = m[key];
					auto temp = 0ll;
					for (auto k = N - 1; k >= 0; k -= d2)
					{
						temp += s[k];
						tempS.push_back(temp);
					}
				}
				auto& sum = m[key];
				key = d2 * (ll)N + A % d2;
				if (m.count(key) == 0)
				{
					auto& tempS = m[key];
					auto temp = 0ll;
					for (auto k = N - 1 - (A % d2); k >= 0; k -= d2)
					{
						temp += s[k];
						tempS.push_back(temp);
					}
				}
				auto& sum2 = m[key];

				auto sumA = sum[remain / d2];
				auto sumB = sum2[(N - 1) / d2] - sum2[(A / d2) - 1];
				result = max(result, sumA + sumB);
			}
		}
		if(remain < A)
		{
			auto sumA = s[A];
			auto sumB = s[N - 1 - A];
			result = max(result, sumA + sumB);
		}
	}

	cout << result << endl;

	return 0;
}