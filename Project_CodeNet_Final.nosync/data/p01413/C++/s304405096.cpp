#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
ld eps=1e-9;

struct good {
	long long int sell;
	int weight;
};
struct city{
	int x;
	int y;
	vector<good>goods;
};
template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first1,
	BidirectionalIterator last1,
	BidirectionalIterator first2,
	BidirectionalIterator last2)
{
	if ((first1 == last1) || (first2 == last2)) {
		return false;
	}
	BidirectionalIterator m1 = last1;
	BidirectionalIterator m2 = last2; --m2;
	while (--m1 != first1 && !(*m1 < *m2)) {
	}
	bool result = (m1 == first1) && !(*first1 < *m2);
	if (!result) {
		// ???
		while (first2 != m2 && !(*m1 < *first2)) {
			++first2;
		}
		first1 = m1;
		std::iter_swap(first1, first2);
		++first1;
		++first2;
	}
	if ((first1 != last1) && (first2 != last2)) {
		// ???
		m1 = last1; m2 = first2;
		while ((m1 != first1) && (m2 != last2)) {
			std::iter_swap(--m1, m2);
			++m2;
		}
		// ??¢
		std::reverse(first1, m1);
		std::reverse(first1, last1);
		std::reverse(m2, last2);
		std::reverse(first2, last2);
	}
	return !result;
}

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first,
	BidirectionalIterator middle,
	BidirectionalIterator last)
{
	return next_combination(first, middle, middle, last);
}
int main() {
	int N, M, W, T; cin >> N >> M >> W >> T;
	map<string, good>mp;
	for (int i = 0; i < M; ++i) {
		string s; int v, p; cin >> s >> v >> p;
		mp[s] = good{ p,v};
	}
	vector<city>citys;
	for (size_t i = 0; i < N; i++)
	{
		int L, X, Y; cin >> L >> X >> Y;
		city acity;
		acity.x = X;
		acity.y = Y;
		if (!L)continue;
		while(L--)
		{
			string r; int q; cin >> r >> q;
			if (q < mp[r].sell) {
				acity.goods.push_back(good{  mp[r].sell-q,mp[r].weight});
			}
		}
		citys.push_back(acity);
	}
	city start;
	start.x = 0; start.y = 0;
	citys.push_back(start);
	vector<vector<int>>diss(N + 1, vector<int>(N + 1));
	for (int i = 0; i < N +1; ++i) {
		for (int j = 0; j < N + 1; ++j) {
			diss[i][j] = abs(citys[i].x - citys[j].x) + abs(citys[i].y - citys[j].y);
		}
	}
	map<int, long long int>dismp;
	for (int gocity = 1; gocity <= N; ++gocity) {
		vector<int>perms(N);
		iota(perms.begin(), perms.end(), 0);
		do {

			map<int, long long int>nowgoods;
			for (int i = 0; i < gocity; ++i) {
				city acity = citys[perms[i]];
				for (auto g : acity.goods) {
					if (nowgoods.find(g.weight) == nowgoods.end()) {
						nowgoods[g.weight] = g.sell;
					}
					else {
						nowgoods[g.weight] =max(nowgoods[g.weight], g.sell);
					}
				}
			}


			int minlen = 1e8;
			do {
				int len = diss[N][perms[0]];
				for (int i = 0; i < gocity; ++i) {
					if (i != gocity - 1)len += diss[perms[i]][perms[i + 1]];
				}
				len += diss[perms[gocity - 1]][N];
				minlen = min(minlen, len);
			} while (next_permutation(perms.begin(), perms.begin() + gocity));

			vector<long long int>dp(W + 1, 0);
			for (int w = 0; w <= W; ++w) {
				for (auto g : nowgoods) {
					if (w + g.first <= W) {
						dp[w + g.first] = max(dp[w + g.first], dp[w] + g.second);
					}
				}
			}

			if (dismp.find(minlen) == dismp.end()) {
				dismp[minlen] = *max_element(dp.begin(), dp.end());
			}
			else {
				dismp[minlen] = max(dismp[minlen], *max_element(dp.begin(), dp.end()));
			}
		} while (next_combination(perms.begin(), perms.begin() + gocity, perms.end()));
		
	}
	vector<long long int>dp2(T + 1, 0);
	for (int t = 0; t <= T; ++t) {
		for (auto d : dismp) {
			const int nextt = t + d.first;
			if (nextt <= T) {
				dp2[nextt] = max(dp2[nextt], dp2[t] + d.second);
			}
		}
	}
	long long int ans = dp2[T];
	cout << ans << endl;
	return 0;
}