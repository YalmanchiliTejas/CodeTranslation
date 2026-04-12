#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    for(;;){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0)
            return 0;

        vector<int> a(n+m);
        for(int i=0; i<n+m; ++i)
            cin >> a[i];
        inplace_merge(a.begin(), a.begin()+n, a.end());

        int ret = a[0];
        for(int i=1; i<n+m; ++i)
            ret = max(ret, a[i] - a[i-1]);
        cout << ret << endl;
    }
}