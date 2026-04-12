#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> edge(N, vector<bool>(N, false));
    vector<int> P(N);

    for (int i = 0; i < M; i++) {
        int n, m;
        cin >> n >> m;
        edge[n-1][m-1] = true;
        edge[m-1][n-1] = true;
    }

    for (int i = 0; i < N; i++) {
        P[i] = i;
    }

    int count = 0;
    do {
        if (P[0] != 0) {
            break;
        }
        bool flag = true;
        for (int i = 0; i < N - 1; i++) {
            if (!edge[P[i]][P[i+1]]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            count++;
        }
    }while (next_permutation(P.begin(), P.end()));
    
    cout << count << endl;
    return 0;
}