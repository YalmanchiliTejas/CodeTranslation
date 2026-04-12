#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
using namespace std;
using Int = long long;
#include <bitset>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,f,t) for(int i=f;i<t;i++)
#define P(r) do{for(auto i:r){cout<<i<<' ';}cout<<'\n';}while(0)
int main()
{
    int N, M; cin >> N >> M;
    int path[8] = {};
    REP(i, M) {
        int a, b; cin >> a >> b;
        a--, b--;
        path[a] |= 1 << b;
        path[b] |= 1 << a;
    }
    function<int(int, int)> recur;
    int finish = (1 << N) - 1;
    recur = [&](int i, int visited) -> int {
        visited |= 1 << i;
        if (visited == finish) return 1;
        int cnt = 0;
        int next = path[i] & ~visited;
        REP(j, N) if (next & (1 << j)) {
            cnt += recur(j, visited);
        }
        return cnt;
    };
    cout << recur(0, 0) << endl;
    return 0;
}
