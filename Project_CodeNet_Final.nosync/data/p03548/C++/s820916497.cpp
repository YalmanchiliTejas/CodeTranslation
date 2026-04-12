#include <bits/stdc++.h>

#define pp push_back
#define pf push_front
#define mp make_pair
#define fs first
#define sc second
#define sf scanf

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = (int) 1e9;

int main(int argc, char *argv[])
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int x, y, z;
	cin >> x >> y >> z;
	int ans = (x - z) / (y + z);
	cout << ans;

	return 0;
}
