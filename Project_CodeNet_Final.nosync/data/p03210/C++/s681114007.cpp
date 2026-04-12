#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int a;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a;
	if (a == 7 || a == 5 || a == 3)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
