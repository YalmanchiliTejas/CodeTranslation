#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime> 
#include <memory.h>
#include <assert.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18 + 1;

int main() {
    int N;
    cin >> N;
    int ma = -1;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int H;
        cin >> H;
        if (H >= ma) {
            ma = H;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}