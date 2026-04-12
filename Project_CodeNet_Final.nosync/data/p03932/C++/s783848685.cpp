#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

signed main()
{
    int h, w;
    cin >> h >> w;
    
    vvi miyage(h, vi(w));
    
    rep(i, h) rep(j, w){
        cin >> miyage[i][j];
    }
    
    vector<vvi> dp(h+w-1, vvi(h, vi(h)));
    dp[0][0][0] = miyage[0][0];
    
    reps(k, 1, h+w-1){
        rep(i1, h) rep(i2, h){
            int j1 = k - i1;
            int j2 = k - i2;
            if(j1<0 || w<=j1 || j2<0 || w<=j2) continue;
            
            int a1 = miyage[i1][j1];
            int a2 = miyage[i2][j2];
            int sum = i1 == i2 ? a1 : a1 + a2;
            
            int di1[] = {0, -1, 0, -1};
            int di2[] = {0, 0, -1, -1};
            rep(m, 4){
                int pi1 = i1 + di1[m];
                int pi2 = i2 + di2[m];
                if(pi1 >= 0 && pi2 >= 0){
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][pi1][pi2] + sum);
                }
            }
        }
    }
    
    cout << dp[h+w-2][h-1][h-1] << endl;
}
