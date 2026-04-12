#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	vector <int> A;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	sort(A.begin(), A.end());

	vector <int> B;
	B.push_back(A[0]);
	A.erase(A.begin());
	int cnt = 1;
	while (true) {
		if (cnt == N)break;
		B.insert(B.begin(), A.back());
		A.pop_back();
		cnt++;
		if (cnt == N)break;

		B.push_back(A.back());
		A.pop_back();
		cnt++;
		if (cnt == N)break;

		B.insert(B.begin(), A.front());
		A.erase(A.begin());
		cnt++;
		if (cnt == N)break;

		B.push_back(A.front());
		A.erase(A.begin());
		cnt++;
		if (cnt == N)break;
	}
	
	long long out1 = 0;
	long long out2 = 0;
	long long out3 = 0;
	for (int i = 0; i < N - 1; i++) {
		out1 = out1 + abs(B[i] - B[i + 1]);
	}
	out2 = out1 - abs(B[0] - B[1]) + abs(B[0] - B[N - 1]);
	out3 = out1 - abs(B[N-2] - B[N-1]) + abs(B[0] - B[N - 1]);
	cout << max(out3,max(out1,out2));
	return 0;
}