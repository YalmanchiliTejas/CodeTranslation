#include "bits/stdc++.h"
using namespace std;

int N, M;
int p[10];
pair<int, int> AB[50];

int ans = 1;
void dfs(int pos, int mask) { 
    //順列生成. pos:既に決定している個数, mask:残りの数の集合
    if (pos == N) { //生成した順列に従い処理
        if (p[0] != 0) return;
        for (int i = 1; i < N; i++) {
            bool flag = false;
            for (int j = 0; j < M; j++) {
                if (make_pair(p[i - 1], p[i]) == AB[j] || make_pair(p[i], p[i - 1]) == AB[j]) {
                    flag = true;
                }
            }
            if (!flag) {
                ans--;
                break;
            }
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) { //iが未使用のとき
            p[pos] = i;
            dfs(pos + 1, mask ^ (1 << i)); //iを使用済にする
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> AB[i].first >> AB[i].second;
        AB[i].first--;
        AB[i].second--;
    }

    for (int i = 1; i < N; i++) ans *= i;
    dfs(0, (1 << N) - 1);
    cout << ans << endl;
}