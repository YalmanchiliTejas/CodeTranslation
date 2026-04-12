#include<bits/stdc++.h>
using namespace std;
long long k,a,b;
int main() {
	ios::sync_with_stdio(false);
	cin >> k >> a >> b;
	if(k <= a)
		cout << "1\n";
	else if(a <= b)
		cout << "-1\n";
	else
		cout << (k - b - 1) / (a - b) * 2 + 1 << endl;
	return 0;
}