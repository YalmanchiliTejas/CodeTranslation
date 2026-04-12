#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;

void Main()
{
    int N, M; cin >> N >> M;
    vector<int> v;
    REP(i, 2, N + 1) v.push_back(i);
    int con[15][15];
    memset(con, 0, sizeof con);
    rep(i, M)
    {
        int a, b; cin >> a >> b;
        con[a][b] = 1;
        con[b][a] = 1;
    }
    
    int res = 0;
    do {
        bool ok = true;
        rep(i, v.size())
        {
            if (i == 0) {
                if (!con[1][v[i]]) {
                    ok = false;
                }
            } else {
                if (!con[v[i - 1]][v[i]]) {
                    ok = false;
                }
            }
        }
        if (ok) ++res;
    } while(next_permutation(v.begin(), v.end()));
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
