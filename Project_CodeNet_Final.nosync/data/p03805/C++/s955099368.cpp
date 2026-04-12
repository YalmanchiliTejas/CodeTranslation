#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,n,s) for(int i=(int)(s);i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

int main() {
    int n,m;cin>>n>>m;
    vector<vector<int>> e(n, vector<int>(0));
    REP(i,m) {
        int a,b;cin>>a>>b;
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int ans = 0;
    stack<vector<int>> s;
    s.push(vector<int>(1,0));
    while(!s.empty()) {
        vector<int> path = s.top();
        s.pop();

        FOR(i, e[path.back()]) {
            if(find(ALL(path), *i) != path.end()) continue;
            if(path.size()+1 == n) {
                ans++;
                continue;
            }
            path.push_back(*i);
            s.push(vector<int>(path));
            path.pop_back();
        }
    }

    cout << ans << endl;
}
