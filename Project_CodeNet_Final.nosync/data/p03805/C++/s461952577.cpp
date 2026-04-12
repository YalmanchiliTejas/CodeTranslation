#include <stdio.h>

#define MAX 8

int N,ans = 0;

void visit(int r, int C[][MAX+1], int u[])
{
    int f = 1;
    int B[MAX+1][MAX+1];
    int w[MAX+1];

    for (int i = 0; i <= N; i++) {
        w[i] = u[i];
        for (int j = 0; j <= N; j++) {
            B[i][j] = C[i][j];
        }
    }
    w[r] = 1;
    for (int i = 1; i <= N; i++) {
        if (w[i] == 0) {
            f = 0;
            break;
        }
    }
    if (f == 1) {
        ans++;
    }
    for (int i = 1; i <= N; i++) {
        if (B[r][i] == 1 && w[i] == 0) {
            visit(i,B,w);
        }
    }
}

int main(void)
{
    int A[MAX+1][MAX+1];
    int v[MAX+1];
    int M;
    int a, b;

    scanf("%d%d",&N,&M);

    for (int i = 0; i <= N; i++) {
        v[i] = 0;
        for (int j = 0; j <= N; j++) {
            A[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%d%d",&a,&b);
        A[a][b] = A[b][a] = 1;
    }

    visit(1, A, v);
    printf("%d\n",ans);
    return 0;
}
