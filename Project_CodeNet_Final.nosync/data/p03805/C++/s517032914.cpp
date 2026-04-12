#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for(int i = 1; i < N; i++) {
        v.push_back(i);
    }

    vector<vector<bool> > c(N, vector<bool>(N));

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        c[a][b] = true;
        c[b][a] = true;
    }

    int ans = 0;

    do {
        int pos = 0;
        bool checker = false;
        for(int i = 0; i < N - 1; i++) {
            if(!c[pos][v[i]]) {
                checker = true;
                break;
            }
            pos = v[i];
        }
        if(checker) continue;
        ans++;
    } while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}