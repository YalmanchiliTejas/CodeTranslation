#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;

#ifdef DEBUG
#define LOG(args) cout << args << "\n"
#define debug(x) x
#else
#define LOG(args)
#define debug(x)
#endif

#define vi vector<int>
#define ii pair<int, int>
#define vii vector< ii >
#define vvi vector< vi >
#define mp make_pair
#define pb push_back
#define ms(x, v) memset(x, v, sizeof(x))
#define all(x) x.begin(), x.end()
#define REP(x, n) for(int x = 0; x < n; x++)
#define REPV(x, v, n) for(int x = v; x < n; x++)
#define REVE(x, n) for(int x = n; x >= 0; x--)

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x;
	cin >> x;
	if(x >= 30)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
