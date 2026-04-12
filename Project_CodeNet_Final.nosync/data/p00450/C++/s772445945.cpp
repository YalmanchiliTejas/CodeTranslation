#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

pair<int, int> stone[100000];

int main() {
	while (true) {
		int n, c, pos = 0;
		cin >> n;
		if (n == 0) break;

		REP(i, n) { stone[i].first = stone[i].second = 0; }

		scanf("%d", &c);
		stone[++pos] = MP(c, 1);

		FOR(i, 1, n) {
			scanf("%d", &c);

			if ((i + 1) % 2 == 1) {
				if (stone[pos].first == c) stone[pos].second++;
				else stone[++pos] = MP(c, 1);
			} else {
				if (stone[pos].first == c)
					stone[pos].second++;
				else {
					if (pos == 0) {
						stone[pos].first = c;
						stone[pos].second++;
					} else {
						stone[pos - 1].second += ++stone[pos].second;
						stone[pos].first = stone[pos].second = 0;
						pos--;
					}
				}
			}
		}

		int ans = 0;
		REP(i, pos + 1) if (stone[i].first == 0) ans += stone[i].second;
		cout << ans << endl;
	}
	return 0;
}