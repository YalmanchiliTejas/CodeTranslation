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

long long solve(int n, long long x)
{
    vector<long long> burger(n, 1);
    vector<long long> patty(n, 1);
    for(int i=1; i<n; ++i){
        burger[i] = burger[i-1] * 2 + 3;
        patty[i] = patty[i-1] * 2 + 1;
    }

    long long ans = 0;
    for(int i=n-1; i>=0 && x > 0; --i){
        if(x <= burger[i] + 1){
            -- x;
        }
        else if(x <= burger[i] * 2 + 2){
            x -= burger[i] + 2;
            ans += patty[i] + 1;
        }
        else{
            ans += patty[i] * 2 + 1;
            x = 0;
        }
    }
    ans += x;

    return ans;
}

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    cout << solve(n, x) << endl;

    return 0;
}
