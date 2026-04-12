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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    map<long long, int> memo;
    long long sum = 0;
    int ans = 0;
    for(int i=0; i<n; ++i){
        if(memo.find(sum) == memo.end())
            memo[sum] = i;
        sum += v[i];
        if(memo.find(sum) != memo.end())
            ans = max(ans, i - memo[sum] + 1);
    }
    cout << ans << endl;

    return 0;
}