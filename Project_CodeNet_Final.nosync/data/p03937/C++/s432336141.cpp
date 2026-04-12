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
    int h, w;
    cin >> h >> w;
    vector<string> data(h+1);
    FOR(i, 0, h) {
        cin >> data[i];
        data[i].push_back('.');
    }
    data[h].resize(w + 1);
    FOR(i, 0, w+1) {
        data[h][i] = '.';
    }
    if (data[0][0] == '.' || data[h - 1][w - 1] == '.') {
        cout << "Impossible" << endl;
        return 0;
    }
    int posy = 0, posx = 0;
    bool res = true;
    while (posx != w - 1 || posy != h - 1) {
        if ((posx > 0 && data[posy][posx - 1] == '#') || (posy > 0 && data[posy - 1][posx] == '#')) {
            res = false;
            break;
        }
        if (data[posy + 1][posx] == data[posy][posx + 1]) {
            res = false;
            break;
        }
        data[posy][posx] = '.';

        if (data[posy + 1][posx] == '#') {
            posy++;
        }
        else
            posx++;
    }
    if (res && (data[posy - 1][posx] == '#' || data[posy][posx - 1] == '#'))
        res = false;
    cout << (res ? "Possible" : "Impossible") << endl;
    return 0;
}