#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
#include<unordered_map>
#include<map>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<ll>;


int main()
{
	int N;
	cin >> N;

	map<int, int> mp;

	for (int i = 0; i < N; ++i)
	{
		int A; cin >> A;
		mp[A]++;

		auto itr = mp.find(A);
		if (itr != mp.begin())
		{
			--itr;
			itr->second--;
			if (itr->second == 0)
			{
				//cout << "*" <<endl;
				int B = itr->first;
				mp.erase(B);
			}
		}
	}

	int ans = 0;
	for(auto & itr : mp)
	{
		ans += itr.second;
	}
	cout << ans << endl;
	return 0;
}