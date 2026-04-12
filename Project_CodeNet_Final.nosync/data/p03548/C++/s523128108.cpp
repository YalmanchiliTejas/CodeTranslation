#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define SORT(i) sort((i).begin(),(i).end())
#define INF 2000000000
constexpr ll mod = 1000000007;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	y += z;
	cout << x / y << "\n";

	return 0;
}