#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <assert.h>

using namespace std;

int h, w, c, m, nw, nc, nm;
inline int SOURCE() { return (h + w + c + m) * 2; }
inline int DISTINATION() { return (h + w + c + m) * 2 + 1; }
inline int WARRIOR_SUB_IN() { return (h + w + c + m) * 2 + 2; }
inline int WARRIOR_SUB_OUT() { return (h + w + c + m) * 2 + 3; }
inline int CLERIC_SUB_IN() { return (h + w + c + m) * 2 + 4; }
inline int CLERIC_SUB_OUT() { return (h + w + c + m) * 2 + 5; }
inline int MAGE_SUB_IN() { return (h + w + c + m) * 2 + 6; }
inline int MAGE_SUB_OUT() { return (h + w + c + m) * 2 + 7; }
inline int SIZE() { return (h + w + c + m) * 2 + 8; }
inline int HERO_IN(int n) { return n; }
inline int HERO_OUT(int n) { return h + n; }
inline int WARRIOR_IN(int n) { return h * 2 + n; }
inline int WARRIOR_OUT(int n) { return h * 2 + w + n; }
inline int CLERIC_IN(int n) { return h * 2 + w * 2 + n; }
inline int CLERIC_OUT(int n) { return h * 2 + w * 2 + c + n; }
inline int MAGE_IN(int n) { return h * 2 + w * 2 + c * 2 + n; }
inline int MAGE_OUT(int n) { return h * 2 + w * 2 + c * 2 + m + n; }

int matrix[1000][1000];
int parent[1000];

int main() {
    while (scanf("%d %d %d %d %d %d %d", &h, &w, &c, &m, &nw, &nc, &nm), h != -1) {
    assert(SIZE() < 1000);
    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < h; i++) {
      matrix[SOURCE()][HERO_IN(i)] = 1;
      matrix[HERO_IN(i)][HERO_OUT(i)] = 1;
      matrix[HERO_OUT(i)][WARRIOR_SUB_IN()] = 1;
    }
    for (int i = 0; i < w; i++) {
      matrix[WARRIOR_IN(i)][WARRIOR_OUT(i)] = 1;
      matrix[WARRIOR_OUT(i)][CLERIC_SUB_IN()] = 1;
    }
    matrix[WARRIOR_SUB_IN()][WARRIOR_SUB_OUT()] = nw;
    for (int i = 0; i < c; i++) {
      matrix[CLERIC_IN(i)][CLERIC_OUT(i)] = 1;
      matrix[CLERIC_OUT(i)][MAGE_SUB_OUT()] = 1;
      matrix[WARRIOR_SUB_OUT()][CLERIC_IN(i)] = 1;
    }
    matrix[CLERIC_SUB_IN()][CLERIC_SUB_OUT()] = nc;
    for (int i = 0; i < m; i++) {
      matrix[MAGE_IN(i)][MAGE_OUT(i)] = 1;
      matrix[MAGE_OUT(i)][DISTINATION()] = 1;
      matrix[CLERIC_SUB_OUT()][MAGE_IN(i)] = 1;
    }
    matrix[MAGE_SUB_IN()][MAGE_SUB_OUT()] = nm;
    matrix[MAGE_SUB_OUT()][DISTINATION()] = nm;
    for (int i = 0; i < w; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int a;
            scanf("%d", &a);
            a--;
            matrix[HERO_OUT(a)][WARRIOR_IN(i)] = 1;
        }
    }
    for (int i = 0; i < c; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int a;
            scanf("%d", &a);
            a--;
            matrix[WARRIOR_OUT(a)][CLERIC_IN(i)] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int a;
            scanf("%d", &a);
            a--;
            matrix[CLERIC_OUT(a)][MAGE_IN(i)] = 1;
        }
    }
    int ans = 0;
    while (true) {
        memset(parent, -1, sizeof(parent));
        queue<int> que;
        que.push(SOURCE());
        parent[SOURCE()] = SOURCE();
        while (!que.empty()) {
            int where = que.front();
            que.pop();
            if (where == DISTINATION()) { break; }
            for (int i = 0; i < SIZE(); i++) {
                if (parent[i] != -1 || matrix[where][i] <= 0) { continue; }
                parent[i] = where;
                que.push(i);
            }
        }
//        for (int j=0;j<=SIZE();++j) {
//            cout<<j<<":"<<parent[j]<<endl;
//        }
//        cout<<endl;
        if (parent[DISTINATION()] == -1) { break; }
        int from = parent[DISTINATION()];
        int to = DISTINATION();
        while (to != SOURCE()) {
            matrix[from][to]--;
            matrix[to][from]++;
            from = parent[from];
            to = parent[to];
        }
        ans++;
    }
    printf("%d\n", ans);
}
    return 0;
}