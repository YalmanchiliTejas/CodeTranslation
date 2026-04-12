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

    vector<int> cnt(128, INT_MAX);
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;
        vector<int> v(128, 0);
        for(char c : s)
            ++ v[c];
        for(char c='a'; c<='z'; ++c)
            cnt[c] = min(cnt[c], v[c]);
    }

    string ans;
    for(char c='a'; c<='z'; ++c){
        while(cnt[c] > 0){
            ans += c;
            -- cnt[c];
        }
    }
    cout << ans << endl;

    return 0;
}
