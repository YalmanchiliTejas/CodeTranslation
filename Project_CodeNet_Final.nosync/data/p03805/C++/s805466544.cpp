#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int edge[8][8];
    int N, M, a, b, count = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) edge[i][j] = 0;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edge[a - 1][b - 1] = edge[b - 1][a - 1] = 1;
    }
    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);

    do {
        if (v[0] != 0) continue;
        bool flag = false;
        for (int i = 1; i < v.size(); i++) {
            if (edge[v[i - 1]][v[i]] != 1) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        count++;
    } while (next_permutation(v.begin(), v.end()));

    cout << count << endl;
    return 0;
}