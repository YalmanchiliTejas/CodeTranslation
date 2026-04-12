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
    string s;
    cin >> n >> s;

    for(int i=0; i<4; ++i){
        string ans(n, ' ');
        ans[0] = (i&1) ? 'S' : 'W';
        ans[1] = (i&2) ? 'S' : 'W';

        for(int j=1; j<n-1; ++j){
            if((ans[j] == 'W') ^ (s[j] == 'x'))
                ans[j+1] = 'S' + 'W' - ans[j-1];
            else
                ans[j+1] = ans[j-1];
        }

        if((ans[0] == 'W') ^ (s[0] == 'x') ^ (ans[n-1] != ans[1]))
            continue;
        if((ans[n-1] == 'W') ^ (s[n-1] == 'x') ^ (ans[n-2] != ans[0]))
            continue;

        cout << ans << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}
