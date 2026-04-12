#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const int maxn = 1e5 + 7;

char s[maxn];
deque<char>dq;

int main() {
    string s;
    while(cin >> s) {
        if(s[0] == s[1] && s[0] == s[2]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
