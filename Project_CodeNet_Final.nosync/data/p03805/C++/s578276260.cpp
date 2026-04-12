#include <bits/stdc++.h>
#include <algorithm>
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, a, b) for(int i = a; i >= b; --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
const int INF = 1e9;
typedef long long ll;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int G[8][8] = {};
    int ans = 0;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = 1;
    }
    vector<int> nums(n);
    REP(i, n) {
        nums[i] = i;
    }
    do {
        bool flag = true;
        FOR(i, 0, n-1) {
            if(!G[nums[i]][nums[i+1]]) flag = false;
        }
        if(flag) ans++;
    }while(next_permutation(nums.begin()+1, nums.end()));
    cout << ans << endl;
}