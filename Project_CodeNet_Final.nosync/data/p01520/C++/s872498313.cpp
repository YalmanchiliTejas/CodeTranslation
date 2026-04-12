#include <cstdio>
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
    int n, t, e;
    cin >> n >> t >> e;

    for(int i=1; i<=n; ++i){
        int x;
        cin >> x;

        int t2 = t / x * x;
        if(t-e <= t2 && t2 <= t+e || t-e <= t2+x && t2+x <= t+e){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}