#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


ll func(ll bottom, int level){
    if(level == 0 && bottom == 1)
        return 1;
    ll total = 4;
    REP(i, level)
        total *= 2;
    total -= 3;

    
    ll half = total / 2 + 1;
    if(bottom == 1)
        return 0;
    else if(bottom < half){
        return func(bottom-1, level-1);
    }
    else if(bottom == half){
        return func(half-2, level-1) + 1;
    }
    else if(bottom < total){
        return func(half-2, level-1) + func(bottom - half, level-1) + 1;
    }
    else{
        return 2 * func(half-2, level-1) + 1;
    }
}
int main() {
    ll n, x;
    cin >> n >> x;

    cout << func(x, n) << endl;

    return 0;
}