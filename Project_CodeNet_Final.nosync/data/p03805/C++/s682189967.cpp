#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<vector <int> > g(N, vector<int>(N, 0));

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        g[a][b] = g[b][a] = 1;
    }

    vector<int> v(N);
    iota(v.begin(), v.end(), 1);
    int ans = 0;
    do {
        int previous = 1;
        bool flag = true;
        for(int i = 0; i < N; i++) {

            if(i == 0) { 
                if(v[0] != 1) {
                    flag = false;
                    break;
                }
            }
            else if(g[previous-1][v[i]-1] == 1) {
                    previous = v[i];
            }
            else {
                flag = false;
                break;
            }
        }
        if(flag)    ans++;
    } while(next_permutation(v.begin(), v.end()) );

    cout << ans << endl;
    return 0;
}