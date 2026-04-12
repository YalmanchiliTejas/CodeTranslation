#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int main() {

	int N;
	cin >> N;
	std::vector<int> h;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		h.push_back(tmp);
	}
	int count = 1;
	
	for (int i = 1; i < N; i++) {
		int ni = h[i];
		bool canlook = true;
		for (int j = 0; j < i; j++) {
			if (ni >= h[j]) {
				canlook = true;
			}
			else {
				canlook = false;
				break;
			}
		}
		if (canlook == true) {
			count += 1;
		}

	}

    cout << count << endl;

	return 0;
}
