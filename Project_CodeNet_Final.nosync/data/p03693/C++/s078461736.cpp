#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int inf = 1e9;
const ll linf = 1LL << 50;

int main(int argc, char const* argv[])
{
	int r, g, b;
	cin >> r >> g >> b;
	if((10 * g + b) % 4 == 0)cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
