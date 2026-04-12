#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <limits>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned                    ui;
typedef int                         si;
typedef long                        sl;
typedef long long                   ll;
typedef unsigned long long          ull;

#ifdef LOCALHOST
std::ifstream in("input.txt", std::ifstream::in);
#endif // LOCALHOST

#ifdef LOCALHOST
#define is in
#else
#define is cin
#endif // LOCALHOST

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    if (m >= n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
