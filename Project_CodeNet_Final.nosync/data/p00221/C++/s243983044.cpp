#include<bits/stdc++.h>

using namespace std;

int M, N;
vector<int> Players;
string Expected, Words;


void getExpectedAnswer(int data) {
	stringstream ss;

	if (data % 3 == 0 && data % 5 == 0) {
		Expected = "FizzBuzz";
		return;
	}

	if (data % 3 == 0) {
		Expected = "Fizz";
		return;
	}

	if (data % 5 == 0) {
		Expected = "Buzz";
		return;
	}

	ss << data;
	ss >> Expected;
	//Expected = data + '0';
}

void show() {
	int size;

	size = Players.size();
	for (int i = 0; i < size; ++i) {
		cout << Players[i];
		if (i != size-1) {
			cout << " ";
		}
	}
	cout << endl;
}

int main() {
	vector<int>::iterator iter;

	while (cin >> M >> N, M) {
		Players.clear();
		for (int i = 0; i < M; ++i) {
			Players.push_back(i+1);
		}
		iter = Players.begin();

		for (int cnt = 0; cnt < N; ++cnt) {
			cin >> Words;
			if (Players.size() == 1) {
				continue;
			}
			getExpectedAnswer(cnt+1);
			//cout << "expected:" << Expected << endl;
			if (Words != Expected) {
				iter = Players.erase(iter);
			}
			else {
				++iter;
			}
			if (iter == Players.end()) {
				iter = Players.begin();
			}
		}
		show();
	}

	return 0;
}
