#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>

#define DIV 1000000007
using namespace std;

bool judge(vector<int> &per, vector<pair<int, int>> &edge) {
    int N = per.size() + 1;
    int M = edge.size();
    bool flag = 1;
    
    vector<int> junretu(N);
    junretu[0] = 1;
    for (int i = 0; i < N - 1; i++)
        junretu[i + 1] = per[i];
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M; j++) {
            if (junretu[i] == edge[j].first && junretu[i + 1] == edge[j].second) {
                break;
            }
            if (junretu[i + 1] == edge[j].first && junretu[i] == edge[j].second) {
                break;
            }
            if (j == M - 1) {
                flag = 0;
            }
        }
        if (!flag) break;
    }
    
    if (flag) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edge(M);
    for (int i = 0; i < M; i++)
        cin >> edge[i].first >> edge[i].second;

    vector<int> per(N-1);
    for (int i = 0; i < N - 1; i++)
        per[i] = i + 2;

    int ans = 0;
    do {
        if (judge(per, edge) == true) {
            ans++;
        }
    } while (next_permutation(per.begin(), per.end()));

    cout << ans << endl;
}
