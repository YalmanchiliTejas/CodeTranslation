#include <stdio.h>
#include <bitset>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

constexpr int N = 8;
constexpr int K = 1 << N;
bool P[N][N];
int A[N][K];

int n;

int compute(int v, int t){
    if(A[v][t] != -1) return A[v][t];
    if(!((t >> v) & 1)) return A[v][t] = 0;
    A[v][t] = 0;
    int nt = t ^ (1 << v);
    REP(i, n) if(P[i][v]) A[v][t] += compute(i, nt);
    return A[v][t];
}

int main(void){
    int m; scanf("%d%d", &n, &m);
    REP(i, n) REP(j, n) P[i][j] = false;
    REP(_, m){
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        P[a][b] = P[b][a] = true;
    }
    int k = 1 << n;
    REP(i, n) REP(j, k) A[i][j] = -1;
    REP(i, n) A[i][1 << i] = 1;
    printf("%d\n", compute(0, k - 1) );
    /*
    REP(i, n) REP(j, k){
      printf("A[%d][", i);
      REP(s, n) putchar('0' + ((j >> s) & 1));
      printf("] = %d\n", A[i][j]);
    }
    */
  
  
    return 0;
}