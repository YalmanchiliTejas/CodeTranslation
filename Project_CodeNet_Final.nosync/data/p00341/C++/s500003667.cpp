#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int lo[12];
	for (int i = 0;i < 12;i++) cin >> lo[i];
	sort(lo, lo + 12);

	if (lo[0] == lo[3] && lo[4] == lo[7] && lo[8] == lo[11])cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}