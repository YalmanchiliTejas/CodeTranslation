#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<int> n;
    for (auto a : s) n.push_back(a - '0');
    int l = n.size();

    vector<vector<vector<int64>>> dp(l+1, vector<vector<int64>>(2, vector<int64>(5,0)));

    dp[0][0][0] = 1;

    for(int64 i = 0; i < l; i++){
        for(int64 smaller = 0; smaller < 2; smaller++){
            for(int64 j = 0; j <= 3; j++){
                for(int64 x = 0; x<= (smaller ? 9 : n[i]); x++){
                    dp[i + 1][smaller || x < n[i]][j + (x!=0? 1 : 0)] += dp[i][smaller][j];
                }
            }
        }
    }
    
    cout << dp[l][0][k] + dp[l][1][k] << endl;
}