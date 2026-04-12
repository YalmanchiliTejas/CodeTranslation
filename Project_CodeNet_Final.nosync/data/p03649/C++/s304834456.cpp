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
    vector<long long> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    long long ans = 0;
    for(;;){
        bool end = true;
        for(int i=0; i<n; ++i){
            if(a[i] >= n){
                long long x = a[i] / n;
                for(int j=0; j<n; ++j)
                    a[j] += x;
                a[i] -= x * (n + 1);
                ans += x;
                end = false;
            }
        }
        if(end)
            break;
    }

    cout << ans << endl;
    return 0;
}
