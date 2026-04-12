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

long long solve(const vector<pair<int, int> >& v)
{
    int n = v.size();
    multiset<int> x;
    multiset<int> y;
    multiset<pair<int, int> > p;
    for(int i=0; i<n; ++i){
        x.insert(v[i].first);
        y.insert(v[i].second);
        p.insert(make_pair(v[i].second, v[i].first));
    }

    long long ans = LLONG_MAX;
    for(;;){
        long long tmp = *x.rbegin() - *x.begin();
        tmp *= *y.rbegin() - *y.begin();
        ans = min(ans, tmp);

        if(p.empty())
            break;

        int a, b;
        tie(a, b) = *p.begin();
        p.erase(p.begin());
        x.erase(x.find(b));
        x.insert(a);
        y.erase(y.find(a));
        y.insert(b);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        v[i].first = min(x, y);
        v[i].second = max(x, y);
    }
    sort(v.begin(), v.end());

    cout << solve(v) << endl;

    return 0;
}
