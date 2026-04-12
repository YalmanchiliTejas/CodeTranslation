#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    if(x == 3 || x == 5 || x == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

