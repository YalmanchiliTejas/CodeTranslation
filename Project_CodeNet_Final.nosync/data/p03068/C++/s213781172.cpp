#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N,K;
	string S;

	cin >> N;
	cin >> S;
	cin >> K;
	int i;
	string res;
	for (i=0; i<S.length(); i++) {
		if (S[i] != S[K-1])
			res += '*';
		else
			res += S[i];
	}
	cout << res << endl;
}
