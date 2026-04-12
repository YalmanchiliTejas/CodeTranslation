//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

#include <stdexcept>

using namespace std;

// type alias
using ll = long long;
using ull = unsigned long long;

ll MOD = 1000000007LL;

//conversion
//------------------------------------------
inline int toint(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class t> inline string tostring(t x) { ostringstream sout; sout << x; return sout.str(); }

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl
#define DEBUG(x) cerr << #x << " = " << (x) << " (l" << __line__ << ")" << " " << __file__ << endl

ll get_lis_length(const vector<ll>& seq, bool strictly = true, bool ascending = true)
{

	vector<ll> min_last_seq_elem;
	using iter_type = decltype(min_last_seq_elem.begin());
	auto get_iter = [&strictly, &ascending](iter_type begin, iter_type end, ll elem)
	{
		if (strictly)
		{
			if (ascending)
				return lower_bound(begin, end, elem, less<ll>());
			else
				return lower_bound(begin, end, elem, greater<ll>());
		}
		else
		{
			if (ascending)
				return upper_bound(begin, end, elem, less<ll>());
			else
				return upper_bound(begin, end, elem, greater<ll>());
		}
	};

	for (auto& elem : seq)
	{
		auto iter = get_iter(min_last_seq_elem.begin(), min_last_seq_elem.end(), elem);
		if (iter == min_last_seq_elem.end())
			min_last_seq_elem.emplace_back(elem);
		else
			*iter = elem;
	}

	return min_last_seq_elem.size();
}

ll get_lis(const vector<ll>& seq, bool strictly = true, bool ascending = true)
{
	vector<ll> min_last_seq_elem;
	using iter_type = decltype(min_last_seq_elem.begin());
	auto get_iter = [&strictly, &ascending](iter_type begin, iter_type end, ll elem)
	{
		if (strictly)
		{
			if (ascending)
				return lower_bound(begin, end, elem, less<ll>());
			else
				return lower_bound(begin, end, elem, greater<ll>());
		}
		else
		{
			if (ascending)
				return upper_bound(begin, end, elem, less<ll>());
			else
				return upper_bound(begin, end, elem, greater<ll>());
		}
	};

	vector<ll> update_pos;
	update_pos.reserve(seq.size());


	for (auto& elem : seq)
	{
		auto iter = get_iter(min_last_seq_elem.begin(), min_last_seq_elem.end(), elem);		

		if (iter == min_last_seq_elem.end())
		{
			min_last_seq_elem.emplace_back(elem);
			update_pos.emplace_back(-1LL);
		}
		else
		{
			*iter = elem;
			update_pos.emplace_back(distance(min_last_seq_elem.begin(), iter));
		}
	}

	return min_last_seq_elem.size();
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> vs(N);
	for (ll i = 0; i < N; ++i)
	{
		cin >> vs[i];
	}

	cout << get_lis_length(vs, false, false) << endl;

	return 0;
}
