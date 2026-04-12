#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool func(vector<int>&);
int main() {
	int N;
	cin >> N;
	vector<int> line(N);
	for (int i = 0; i < N; ++i) {
		cin >> line[i];
	}
	vector<int> line2;
	line2 = line;
	reverse(line2.begin(), line2.end());
	cout << (func(line) && func(line2) ? "yes" : "no") << endl;
	return 0;
}

bool func(vector<int>&line) {
	int fp = 1;
	int power = line.front();
	while (fp < line.size()) {
		if (power < 10)return false;
		power -= 10;
		power = max(power, line[fp++]);
	}
	return true;
}