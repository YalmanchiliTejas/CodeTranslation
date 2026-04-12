#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define ll long long
#define INF (1 << 30)
#define INFLL (1LL << 60)

#define FOR(i,a,b) for(ll i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

int n, m, ans;
pair<int, int> edge[40];

bool vec_find(vector<int> vec, int n) {
    vector<int>::iterator cIter = find(vec.begin(), vec.end(), n);

    return cIter != vec.end();
}

void check(int num, vector<int> vec) {
    if (num == n - 1) {
        ans++;
        return;
    }

    REP(i, m) {
        if (edge[i].first == vec[num] && !vec_find(vec, edge[i].second)) {
            vector<int> vec1 = vec;
            vec1.push_back(edge[i].second);
            check(num + 1, vec1);
        }
        if (edge[i].second == vec[num] && !vec_find(vec, edge[i].first)) {
            vector<int> vec2 = vec;
            vec2.push_back(edge[i].first);
            check(num + 1, vec2);
        }
    }

}

int main() {
    cin >> n >> m;

    REP(i, m) {
        int a, b;
        cin >> a >> b;
        edge[i].first = a;
        edge[i].second = b;
    }

    ans = 0;
    vector<int> vec;
    vec.push_back(1);
    check(0, vec);

    cout << ans << endl;

    return 0;
}