#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <climits>
#include <stack>
#include <string>
#include <random>
#include<set>
struct Vote {
	std::string name;
	int vote;
	bool operator<(const Vote &that) const {
		return (vote == that.vote) ? name > that.name : vote < that.vote;
	}
	bool operator==(const Vote &that) const {
		return vote == that.vote && name == that.name;
	}
	bool operator>(const Vote &that) const {
		return (vote == that.vote) ? name < that.name : vote > that.vote;
	}
};
bool can_take(const std::vector<Vote> &favorite, const Vote vote, int rest_vote, const int count) {
	for (auto i = favorite.size() - count; i < favorite.size(); ++i) {
		if (favorite[i] < vote) {
			if (favorite[i].name < vote.name) {
				rest_vote -= vote.vote - favorite[i].vote;
			}
			else {
				rest_vote -= vote.vote - favorite[i].vote + 1;
			}
			if (rest_vote < 0) return false;
		}
		else {
			return true;
		}
	}
	return true;
}
bool can_take(const std::vector<Vote> &fav, const std::vector<Vote> &no_chara, const int k, const int l, const int count) {
	auto else_count = k - count;
	if (else_count >= no_chara.size()) return true;
	else {
		return can_take(fav, no_chara[no_chara.size() - else_count - 1], l, count);
	}
}

void solve() {
	int n, m, k, l;
	std::cin >> n >> m >> k >> l;
	if (n == 0) return;
	std::vector<Vote> elseC;
	std::vector<Vote> favC;
	{
		std::map<std::string, int> estimated;
		std::string name; int vote;
		for (auto i = 0; i < n; ++i) {
			std::cin >> name >> vote;
			estimated.insert(std::make_pair(name, vote));
		}
		for (auto i = 0; i < m; ++i) {
			std::cin >> name;
			favC.push_back(Vote{ name, estimated[name] });
			estimated.erase(name);
		}
		for (const auto &pair : estimated) {
			elseC.push_back(Vote{ pair.first, pair.second });
		}
		std::sort(elseC.begin(), elseC.end());
		std::sort(favC.begin(), favC.end());
	}
	int left = 0;
	int right = std::min(m, k);
	while (left < right) {
		auto mid = (left + right + 1) / 2;
		if (can_take(favC, elseC, k, l, mid)) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}
	std::cout << right << std::endl;
	solve();

}

int main() {
	solve();
}
/*



*/

