#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    int ans = 0;
    cin >> N >> M;
    vector<int>v(N);
    vector<vector<int>>p(N);

    for (int i = 0; i < N; i++) {
        v[i] = i+1;
    }
    
    for (int i = 0; i < N; i++) {
        vector<int>x;
        p[i] = x;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        p[a-1].push_back(b);
        p[b-1].push_back(a);
    }

    do {
        if (v[0] != 1) {
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < p[v[i]-1].size(); j++) {
                if (p[v[i]-1][j] == v[i+1]) {
                    cnt++; 
                    break;
                }
            }
        }
        if (cnt == N-1) {
            ans++;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
