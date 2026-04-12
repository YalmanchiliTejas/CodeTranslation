#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> res(N),sign(N);
	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;
		if (c == 'o') {
			sign[i] = 1;
		}
		else {
			sign[i] = -1;
		}
	}
	bool find = false;
	for (int fv = 0; !find && fv < 2; ++fv) {
		res[0] = 1 - (2*fv);
		for (int sv = 0; !find && sv < 2; ++sv) {
			res[1] = 1 - (2*sv);
			for (int i = 1; i < N-1; ++i) {
				res[i+1] = res[i]*sign[i]*res[i-1];
			}
			if ((res[0] == res[N-1]*sign[N-1]*res[N-2])&&(res[1] == res[0]*sign[0]*res[N-1])) {
				for (int i = 0; i < N; ++i) {
					if (res[i] > 0) {
						cout << "S";
					}
					else {
						cout << "W";
					}
				}
				cout << endl;
				find = true;
			}
		}
	}
	if (!find) {
		cout << -1 << endl;
	}
	return 0;
}

