#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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

const int INF = INT_MAX / 2;

int main()
{
    for(;;){
        int n, m;
        cin >> n >> m;
        if(n == 0)
            return 0;

        vector<int> a(n);
        for(int i=0; i<n; ++i)
            cin >> a[i];

        vector<int> x(1<<n, 0);
        for(int i=0; i<(1<<n); ++i){
            bitset<10> bs(i);
            for(int j=0; j<n; ++j){
                if(bs[j])
                    x[i] += a[j];
            }
        }

        vector<int> dp(m+1, INF);
        dp[0] = 0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<(1<<n); ++j){
                int y = i + x[j];
                if(y <= m)
                    dp[y] = min(dp[y], dp[i] + 1);
            }
        }

        cout << dp[m] << endl;
    }
}