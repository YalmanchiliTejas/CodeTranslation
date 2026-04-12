#include <iostream>
#include <vector>

using namespace std;

int N;
bool Find;
vector<int> res,sign;

void dfs(int ind) {
	if (Find) {
		return;
	}
	if (ind == N-1) {
		if ((res[0] == res[ind]*sign[ind]*res[ind-1]) && (res[1] == res[0]*sign[0]*res[ind])) {
			for (int i = 0; i < N; ++i) {
				if (res[i] > 0) {
					cout << "S";
				}
				else {
					cout << "W";
				}
			}
			cout << endl;
			Find = true;
		}
		return;
	}
	if (ind < 2) {
		res[ind] = 1;
		if (ind == 1) {
			res[ind+1] = sign[ind]*res[ind-1];
		}
		dfs(ind+1);
		res[ind] = -1;
		if (ind == 1) {
			res[ind+1] = -sign[ind]*res[ind-1];
		}
		dfs(ind+1);
	}
	else {
		res[ind+1] = res[ind]*sign[ind]*res[ind-1];
		dfs(ind+1);
	}
}


int main(void) {
	cin >> N;
	sign = vector<int>(N);
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
	res = vector<int>(N);
	Find = false;
	dfs(0);
	if (!Find) {
		cout << -1 << endl;
	}
	return 0;
}
