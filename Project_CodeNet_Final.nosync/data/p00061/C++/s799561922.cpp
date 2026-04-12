#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main () {
	int x, p;
	vector<int> scores;
	map<int, int> teams;
	while (scanf("%d,%d", &x, &p), x || p) {
		teams[x] = p;
		scores.push_back(p);
	}
	sort(scores.begin(), scores.end());
	scores.erase(unique(scores.begin(), scores.end()), scores.end());
	while (scanf("%d", &x) != EOF) {
		printf("%d\n", static_cast<int>(scores.size() - static_cast<int>(lower_bound(scores.begin(), scores.end(), teams[x]) - scores.begin())));
	}
	return 0;
}