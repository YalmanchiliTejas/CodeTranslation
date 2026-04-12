#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}


vector<int> eds[120000];
int was[120000];
int n; 
int dfs1(int v) {
    was[v] = 1;
    int sum = 0;
    for (int u: eds[v]) {
        if (!was[u])
            sum += dfs1(u);
    }
    if (sum >= 2) {
        cout << "First\n";
        exit(0);
    }
    if (sum) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        eds[a].push_back(b);
        eds[b].pb(a);
    }
    int x = dfs1(0);
    if (x == 1) {
        cout << "First\n";
    }
    else {
        cout << "Second\n";
    }
    return 0;
}


