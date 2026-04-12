#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int main() {
    int n;
    scanf("%d", &n);
    deque<int> ans;
    int sw = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (sw) ans.push_front(tmp);
        else ans.push_back(tmp);
        sw ^= 1;
    }
    if (sw) reverse(ans.begin(), ans.end());
    for (int i : ans) printf("%d ", i);
    puts("");
    return 0;
}
