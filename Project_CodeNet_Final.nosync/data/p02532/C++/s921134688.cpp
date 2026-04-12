#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<char, int> P;
const int MN = 1010;
int main() {
    int n;
    cin >> n;
    char d[120][MN];
    int dc[120] = {};
    while (true) {
        string type;
        cin >> type;
        if (type == "quit") break;
        if (type == "push") {
            int id;
            char c;
            cin >> id >> c;
            d[id][dc[id]] = c;
            dc[id]++;
        } else if (type == "pop") {
            int id;
            cin >> id;
            dc[id]--;
            printf("%c\n", d[id][dc[id]]);
        } else {
            int id1, id2;
            cin >> id1 >> id2;
            dc[id1]--;
            d[id2][dc[id2]] = d[id1][dc[id1]];
            dc[id2]++;
        }
    }
    return 0;
}