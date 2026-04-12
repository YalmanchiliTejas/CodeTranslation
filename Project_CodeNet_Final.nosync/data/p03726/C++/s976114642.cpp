#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

const int MAXN = 100000;

vector<int> g[1 + MAXN];
bool bad = false;

bool match(int node, int father) {
    int sons = 0;
    for (auto son : g[node])
        if (son != father && !match(son, node))
            sons++;
    if (sons > 1) {
        bad = true;
        return false;
    }
    if (sons == 1)
        return true;
    else {
        if (father == 0)
            bad = true;
        return false;
    }
}

int main(){
    //ifstream cin("input.in");
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    match(1, 0);
    if (!bad)
        cout << "Second\n";
    else
        cout << "First\n";
    return 0;
}



