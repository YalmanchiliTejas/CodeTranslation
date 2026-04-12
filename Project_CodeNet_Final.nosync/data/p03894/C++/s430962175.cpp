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
    int n, q;
    cin >> n >> q;
    vector<int> a(q), b(q);
    for(int i=0; i<q; ++i){
        cin >> a[i] >> b[i];
        -- a[i];
        -- b[i];
    }

    vector<bool> v(n, false);
    v[0] = v[1] = true;
    int x = 0;
    for(int i=0; i<q; ++i){
        swap(v[a[i]], v[b[i]]);
        if(x == a[i])
            x = b[i];
        else if(x == b[i])
            x = a[i];

        bool tmp = false;
        for(int j=x-1; j<=x+1; ++j){
            if(0 <= j && j < n)
                v[j] = true;
        }
    }

    int ans = 0;
    for(int i=0; i<n; ++i){
        if(v[i])
            ++ ans;
    }
    cout << ans << endl;

    return 0;
}
