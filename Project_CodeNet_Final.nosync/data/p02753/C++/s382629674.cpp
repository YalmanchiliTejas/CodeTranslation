#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <thread>
#include <mutex>

#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MEMSET(v, h) memset((v), h, sizeof(v))

using namespace std;

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    char s[3];
    scanf("%s", s);
    bool n = s[0] == s[1] && s[1] == s[2];
    printf("%s\n", !n ? "Yes" : "No");
    return 0;
}