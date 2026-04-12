#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > g(N);
    while(M--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> c(N);
    for(int i=0; i<N; i++) {
        c[i] = i;
    }

    int ans = 0;
    do {
        if(c[0] != 0) {
            break;
        }
        bool ok = true;
        for(int i=0; i<N-1; i++) {
            if(find(g[c[i]].begin(), g[c[i]].end(), c[i+1]) == g[c[i]].end()) {
                ok = false;
            }
        }
        if(ok) {
            ans++;
        }
    } while(next_permutation(c.begin(), c.end()));

    cout << ans << endl;
    return 0;
}
