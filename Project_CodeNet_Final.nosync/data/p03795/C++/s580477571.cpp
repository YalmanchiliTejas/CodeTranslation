#include<bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	int cost1, cost2;
	cost1 = 800 * N;
	int op=N/15;
	cost2 = 200 * op;
	cout << cost1 - cost2 << endl;
	return 0;

}