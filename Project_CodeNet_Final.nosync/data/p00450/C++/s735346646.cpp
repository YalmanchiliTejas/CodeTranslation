#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	for(int n; cin >> n, n;) {
		bool first_white;
		vector<int> stone(1, 1);

		int tmp;
		cin >> tmp;
		first_white = (tmp == 0);

		for(int i = 2; i <= n; ++i) {
			int in;
			cin >> in;

 			const int size = stone.size();
			bool same_color = (((size + first_white) & 1) == in);

			if(i & 1) {
				if(same_color)
					++stone[size - 1];

				else
					stone.push_back(1);
			}
			else {
				if(same_color)
					++stone[size - 1];

				else {
					if(size == 1) {
						first_white = !first_white;
						++stone[size - 1];
					}
					else {
						stone[size - 2] += stone[size - 1] + 1;
						stone.pop_back();
					}
				}
			}
		}

		int cnt = 0;
		for(int i = (first_white ? 0 : 1); i < stone.size(); i += 2)
			cnt += stone[i];
		
		cout << cnt << endl;
	}

	return EXIT_SUCCESS;
}