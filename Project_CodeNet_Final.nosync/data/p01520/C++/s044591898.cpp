#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define rep(i, n) for(int i = 0; i < n; i ++)
#define ALL(T) T.begin(), T.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF = 1 << 24;

int main(void){
    int n, t, e; cin >> n >> t >> e;
    int res = -1;

    rep(i, n){
        int x; cin >> x;
        for(int d = -e; d <= e; d ++)
            if(!((t - d) % x)){ res = i + 1; break; }
    }

    cout << res << endl;

    return 0;
}