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

const int INF = INT_MAX / 2;

int main()
{
    int h, w;
    cin >> h >> w;
    if(h == 1 || w == 1){
        int ans = 0;
        for(int i=0; i<h*w; ++i){
            int a;
            cin >> a;
            ans += a;
        }
        cout << ans << endl;
        return 0;
    }

    vector<vector<int> > a(h, vector<int>(w));
    for(int y=0; y<h; ++y){
        for(int x=0; x<w; ++x){
            cin >> a[y][x];
        }
    }

    vector<vector<int> > dp(w, vector<int>(w, 0));
    for(int y=0; y<h; ++y){
        for(int x1=0; x1<w; ++x1){
            for(int x2=x1+1; x2<w; ++x2){
                dp[x1][x2] += a[y][x1] + a[y][x2];
            }
        }
        for(int x1=0; x1<w; ++x1){
            for(int x2=x1+1; x2<w; ++x2){
                dp[x1+1][x2] = max(dp[x1+1][x2], dp[x1][x2] + a[y][x1+1]);
            }
        }
        for(int x1=0; x1<w; ++x1){
            for(int x2=x1+1; x2<w-1; ++x2){
                dp[x1][x2+1] = max(dp[x1][x2+1], dp[x1][x2] + a[y][x2+1]);
            }
        }
    }
    cout << dp[w-2][w-1] << endl;

    return 0;
}