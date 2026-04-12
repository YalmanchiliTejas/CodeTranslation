#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>


using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

int main(void)
{
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> As(N);
    REP(n, N) cin >> As[n];

    vector<int> colors{As[0]};
    
    FOR(i, 1, N) {
        auto a = As[i];
        if (a <= colors[0]) {
            colors.insert(colors.begin(), a);
        }
        else {
            auto it = lower_bound(ALL(colors), a);
            --it;
            *it = a;
        }
    }
    cout << SIZE(colors) << endl;
    return 0;
}
