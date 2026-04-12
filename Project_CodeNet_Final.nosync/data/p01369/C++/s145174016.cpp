#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#define exist(c, s) (s.find(c) != s.npos)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	const string right = "yuiophjklnm";
	for(string input; cin >> input, input != "#";) {
		int ans = 0;
		bool prev_right = exist(input[0], right);
		for(int i = 1; i < (int)input.size(); ++i) {
			bool cur_right = exist(input[i], right);
			if(prev_right != cur_right)
				++ans;

			prev_right = cur_right;
		}

		cout << ans << endl;
	}

	return EXIT_SUCCESS;
}