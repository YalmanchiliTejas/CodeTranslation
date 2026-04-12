#include <iostream>
#include <fstream>

#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define pb push_back
#define mp make_pair


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    // cout.setf(ios::fixed), cout.precision(20);

#ifdef LOCAL
    // ifstream cin("input.txt");
#endif

    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    cout << '\n';

    return 0;
}