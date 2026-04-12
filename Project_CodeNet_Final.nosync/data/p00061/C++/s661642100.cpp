#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
	int no, score;
	multimap<int, int> r;
	while (1) {
		scanf("%d,%d", &no, &score);
		if (!no && !score)
			break;
		r.insert( multimap<int, int>::value_type(score, no) );
	}
	while (cin >> no) {
		int ranking = -1;
		int upper;
		map<int, int>::reverse_iterator it = r.rbegin();
		while (it != r.rend()) {
			if (ranking == -1) {
				ranking = 1;
				upper = it->first;
			}
			if (upper > it->first) {
				ranking++;
				upper = it->first;
			}
			if (it->second == no) {
				cout << ranking << endl;
				break;
			}
			it++;
		}
	}
	return 0;
}