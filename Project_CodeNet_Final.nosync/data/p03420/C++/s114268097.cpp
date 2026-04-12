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
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if(k == 0){
        cout << (n * (long long)n) << endl;
        return 0;
    }

    long long ans = 0;
    for(int b=k+1; b<=n; ++b){
        ans += (n + 1) / b * (b - k);
        int x = (n + 1) % b;
        ans += max(0, x - k);
    }
    cout << ans << endl;

    return 0;
}
