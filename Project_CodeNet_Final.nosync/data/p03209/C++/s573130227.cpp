#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

vector<long long> burger, patty;

long long dfs(int i, long long& x)
{
    if(x == 0)
        return 0;

    if(burger[i] <= x){
        x -= burger[i];
        return patty[i];
    }

    -- x;
    long long ans = dfs(i-1, x);
    if(x > 0){
        -- x;
        ans += dfs(i-1, x) + 1;
        if(x > 0)
            -- x;
    }
    return ans;
}

long long solve(int n, long long x)
{
    burger.assign(n+1, 1);
    patty.assign(n+1, 1);
    for(int i=1; i<=n; ++i){
        burger[i] = burger[i-1] * 2 + 3;
        patty[i] = patty[i-1] * 2 + 1;
    }
    return dfs(n, x);
}

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    cout << solve(n, x) << endl;

    return 0;
}
