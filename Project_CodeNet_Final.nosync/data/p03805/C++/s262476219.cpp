/**
 * Title: C - One-stroke Path
 * Url: https://atcoder.jp/contests/abc054/tasks/abc054_c
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<numeric>
#include<functional>
#include<sstream>
#include<iomanip>
#include<queue>

using namespace std;

#define ll long long

struct to {int node; int len; vector<int> used; };

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> es(n+1, vector<int>());
    for(int i=0; i<m; i++) {
        int ai, bi; cin >> ai >> bi;
        es[ai].push_back(bi);
        es[bi].push_back(ai);
    }
    int ans = 0;
    queue<to> q;
    to t = {1, 1, vector<int>()};
    t.used.push_back(1);
    q.push(t);
    while(!q.empty()) {
        to tmp = q.front();
        q.pop();
        if(tmp.len==n) {
            ans++;
            continue;
        }
        for(int i=0; i<es[tmp.node].size(); i++) {
            if(count(tmp.used.begin(), tmp.used.end(), es[tmp.node][i]) == 0) {
                vector<int> c = tmp.used;
                c.push_back(es[tmp.node][i]);
                to t = {es[tmp.node][i], tmp.len+1, c};
                q.push(t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}