#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<string>
#include<time.h>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using str = string;
template<typename T>
using vec = vector<T>;

#define rep(i, n) for(int i = 0; i < n; ++i)


struct edge {
    int l1;
    int l2;
};

struct node {
    vector<int> link;
};

int n, m, cnt;
vec<edge> ed;
vec<node> nod;

void f(vector<int> pass, int b) {
    pass.push_back(b);
    if (pass.size() == n) {
        cnt++;
        return;
    }
    for (int i : nod[pass.back()].link) {
        for (int j : pass) if (i == j) goto LOOP_END;
        f(pass, i);
    LOOP_END:
        continue;
    }
}

int main() {
    cin >> n >> m;
    nod.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        ed.emplace_back(edge{ a-1, b-1 });
        nod[a - 1].link.push_back(b - 1);
        nod[b - 1].link.push_back(a - 1);
    }
    cnt = 0;
    vector<int> v;
    f(v, 0);
    cout << cnt << endl;
    return 0;
}