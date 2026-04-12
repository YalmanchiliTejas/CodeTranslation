#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	int N;
	cin >> N;
	int S[30];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 1; i < N; i++) {
		if (S[0] <= S[i]) {
			cnt++;
			S[0] = S[i];
		}
	}
	cout << cnt+1 << endl;
}