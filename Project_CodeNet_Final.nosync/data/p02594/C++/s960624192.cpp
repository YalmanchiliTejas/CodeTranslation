//Author: Pakhomovee 
#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <deque>
#include <iomanip>
#include <queue>

using namespace std;
using namespace std::chrono;

void solve()
{
	int x;
	cin >> x;
	if (x >= 30)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	auto start = system_clock::now();

	solve();

	auto end = system_clock::now();
	cerr << "Time: " << duration_cast<milliseconds> (end - start).count() << "ms" << endl;
}