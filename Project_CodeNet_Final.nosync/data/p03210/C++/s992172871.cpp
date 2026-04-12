#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)
#define INF 1<<29;

int main()
{
    int x; cin >> x;
    if(x == 3 || x == 5 || x == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}