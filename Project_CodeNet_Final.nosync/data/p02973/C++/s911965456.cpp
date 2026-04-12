#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define ll long long
#define ull unsigned long long
using namespace std;
void io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

const int MAXN = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int n;
int a[MAXN];
int t[MAXN];
int len;

int main() {
    io();
    memset(t, -1, sizeof(t));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int p = upper_bound(t, t + len, a[i], greater<int>()) - t;
        t[p] = a[i];
        if (p == len) {
            len++;
        }
    }
    cout << len;
}
