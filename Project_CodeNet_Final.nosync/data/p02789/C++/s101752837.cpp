#include<iostream>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin >> N >> M;
	cout << (N == M ? "Yes" : "No") << endl;

	return 0;
}