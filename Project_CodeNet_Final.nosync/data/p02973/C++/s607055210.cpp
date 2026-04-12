#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:16777216")
#pragma warning( disable : 6031)
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>
#include <iomanip>
#include <limits>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define eps (1e-9)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef vector< pii > vpii;
typedef tuple<int, int, int> tiii;
const long long inf = 1e12;

int main()
{
#ifdef LOCAL_MACHINE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout << setprecision(18) << fixed;
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        auto it = mp.upper_bound(-a[i]);

        if (it != mp.end())
        {
            it->second -= 1;
            if (it->second == 0)
                mp.erase(it);
        }
        mp[-a[i]]++;

    }
    int res = 0;
    for (auto it : mp)
        res += it.second;
    cout << res << "\n";
	return 0;
}