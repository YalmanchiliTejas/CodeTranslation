#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
#define INF 100000000

typedef long long ll;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int lr[100];

const string migi = "yuiophjklnm";

int main(void) {
    string s;
    while (cin >> s) {
        if (s == "#") break;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            lr[i] = 0;
            for (int j = 0; j < migi.size(); j++) {
                if (s[i] == migi[j]) {
                    lr[i] = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < s.size()-1; i++) {
            if (lr[i] != lr[i+1]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}