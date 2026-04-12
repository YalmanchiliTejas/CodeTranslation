#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const int MAX_N = 10;
    int N, M, E[MAX_N][MAX_N];
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            E[i][j] = 0;
        }   
    }
    for (int i = 0; i < N; ++i){
        v.push_back(i);
    }
    for (int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        E[a-1][b-1] = 1;
        E[b-1][a-1] = 1;
    }

    int ans = 0;
    do {
        if (v[0] != 0) break;
        // for (int i = 0; i < N; ++i){
        //     cout << v[i] + 1;
        // }cout << endl;

        bool f = true;
        for (int i = 0; i < N-1; ++i){
            if (E[v[i]][v[i+1]] == 0){
                f = false;
                break;
            }
        }
        if (f) ans++;

    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}
