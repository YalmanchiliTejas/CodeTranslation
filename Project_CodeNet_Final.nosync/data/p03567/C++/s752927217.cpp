#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int (i) = 0; (i) < (N); ++(i))
#define READALL(c) for (auto &e : c) { cin >> e; }
#define PRINTALL(c) for (const auto &e : c) { cout << e << "\t"; } cout << "\n";

template <typename T>
using V = vector<T>;

typedef long double ld;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;

	cout << (S.find("AC") != string::npos ? "Yes" : "No") << endl;
	
}