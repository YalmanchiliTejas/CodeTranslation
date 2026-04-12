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

long long solve(const vector<int>& s)
{
    int n = s.size();
    long long ans = 0;
    for(int diff=1; diff<=n/2; ++diff){
        long long sum = 0;
        int x = 0;
        int y = n - 1;
        for(int k=1; (k+1)*diff<n; ++k){
            x += diff;
            if(x == y)
                break;
            y -= diff;
            if(x == y)
                break;
            sum += s[x] + s[y];
            ans = max(ans, sum);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; ++i)
        cin >> s[i];
    cout << solve(s) << endl;

    return 0;
}
