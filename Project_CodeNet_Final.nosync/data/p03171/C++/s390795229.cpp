//run: g++ -std=c++14 -o run_sol.exe solution.cpp -DLOCAL_JUDGE
#include<bits/stdc++.h>
#define INF 0x7fffffff
#define INFLL 1e17
#define PI 2*acos(0.0)
#define show(x) cout<< #x <<" is "<< x <<"\n"
using namespace std;

#define FS first
#define SC second
#define PB(t) push_back(t)
#define LEN(t) ((int)t.size())
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))
#define POPCOUNT __builtin_popcount

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;

VLL nums;
vector<VLL> memo;

LL solve (int ini, int fin, int player) {
    if (ini + 1 == fin) {
        return nums[ini] * player;
    }
    if (memo[ini][fin] > -1) {
        return memo[ini][fin];
    }
    LL res = 0;
    if (player == 1) {
        res = max(solve(ini + 1, fin, 1 - player) + nums[ini], 
                    solve(ini, fin - 1, 1 - player) + nums[fin - 1]);
    } else {
        res = min(solve(ini + 1, fin, 1 - player), 
                    solve(ini, fin - 1, 1 - player));
    }

    return memo[ini][fin] = res;
}

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n; cin >> n; ) {
        nums.assign(n, 0);
        memo.assign(n + 1, VLL(n + 1, -1));
        LL sum = 0;
        for (auto& val : nums) {
            cin >> val;
            sum += val;
        }

        cout << 2 * solve(0, n, 1) - sum << "\n";
    }
return 0;
}