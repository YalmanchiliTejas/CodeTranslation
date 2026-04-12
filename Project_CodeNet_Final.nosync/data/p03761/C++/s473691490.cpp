#define _USE_MATH_DEFINES // for C++  
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iterator>
#include <utility>
#include <set>
#include <random>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <functional>


using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v;
	vector<int> snum;
	string ans;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		v.emplace_back(tmp);
	}
	for (size_t i = 0; i < n; i++)
	{
		snum.emplace_back(v[i].length());
	}
	auto itrrrr = min_element(snum.begin(), snum.end());

	size_t index = std::distance(snum.begin(), itrrrr);

	iter_swap(v.begin(), v.begin() + index);


	for (size_t i = 0; i < v[0].length(); i++)
	{
		if (n == 1)
		{
			ans = v[0];
			break;
		}
		bool flag = false;
		for (size_t j = 0; j < v.size()-1; j++)
		{
			auto itrr = v[j + 1].find(v[0].at(i));
			if (itrr != -1)
			{
				v[j + 1].erase(v[j + 1].begin() + itrr);
			}
			else
			{
				break;
			}
			if (j == v.size()-2)
			{
				ans.push_back(v[0].at(i));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans << endl;

}