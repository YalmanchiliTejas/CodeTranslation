#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

#define FOR(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)

using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a][b] = edges[b][a] = true;
    }
    vector<int> verts(n);
    iota(verts.begin(), verts.end(), 0);

    vector<int> orig(verts);
    int cnt = 0;
    do {
        bool flag = true;
        FOR(i, 0, n - 1) {
            if (!edges[verts[i]][verts[i + 1]]) {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
        next_permutation(verts.begin() + 1, verts.end());

    } while (orig != verts);

    cout << cnt << endl;
    return 0;
}