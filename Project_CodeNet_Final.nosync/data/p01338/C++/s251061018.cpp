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

int toInt(const vector<int>& a){
    int ret = 0;
    for(int i=0; i<5; ++i)
        ret |= max(a[i], 0) << (i*2);
    return ret;
}

vector<int> toVector(int a){
    vector<int> ret(5);
    for(int i=0; i<5; ++i){
        ret[i] = a & 3;
        a >>= 2;
    }
    return ret;
}

int getScore(vector<int>& a, int b){
    int ret = 0;
    for(int i=0; i<5; ++i){
        if(a[i] != -1 && (b & 3))
            ret += 50 + 10 * (b & 3);
        b >>= 2;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;

    while(--n >= 0){
        vector<vector<int> > grade(5, vector<int>(5));
        for(int i=0; i<5; ++i){
            for(int j=0; j<5; ++j){
                cin >> grade[i][j];
                -- grade[i][j];
            }
        }

        vector<int> dp(1<<10, -1);
        dp[toInt(grade[0])] = 0;
        for(int i=0; i<4; ++i){
            vector<int> nextDp(1<<10, -1);
            for(int j=0; j<(1<<10); ++j){
                if(dp[j] == -1)
                    continue;
                for(int k=0; k<(1<<8); ++k){
                    vector<int> a = toVector(j);
                    vector<int> b = grade[i+1];
                    for(int l=0; l<4; ++l){
                        (a[l]   += (k>>(l*2)) & 3) %= 4;
                        (a[l+1] += (k>>(l*2)) & 3) %= 4;
                        (b[l]   += (k>>(l*2)) & 3) %= 4;
                        (b[l+1] += (k>>(l*2)) & 3) %= 4;
                    }
                    int a1 = toInt(a);
                    int b1 = toInt(b);
                    nextDp[b1] = max(nextDp[b1], dp[j] + getScore(grade[i], a1)); 
                }
            }
            dp.swap(nextDp);
        }

        int ret = 0;
        for(int i=0; i<(1<<10); ++i){
            ret = max(ret, dp[i] + getScore(grade[4], i));
        }
        cout << ret << endl;
    }

    return 0;
}