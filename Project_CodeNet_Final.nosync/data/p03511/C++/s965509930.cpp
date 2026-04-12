#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
using namespace std;
string S, T, V1, V2; bool B = false; int L, maxn = 0;
int main() {
	cin >> L >> S >> T;
	while (V1.size() <= 10000000)V1 += S;
	while (V2.size() <= 10000000)V2 += T;
	if (V1 > V2) { swap(S, T); }
	for (int i = 0; i <= L; i += (int)S.size()) {
		if ((L - i) % (int)T.size() != 0)continue;
		maxn = max(maxn, i / (int)S.size());
	}
	string U = "";
	for (int i = 0; i < maxn; i++)U += S;
	while ((int)U.size() < L)U += T;
	cout << U << endl;
	return 0;
}