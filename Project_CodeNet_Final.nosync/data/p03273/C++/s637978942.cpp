#include <bits/stdc++.h>

using namespace std;
int N, M, i, j, a[101][101], I, J;
char c;
bool ok, Ok;
int main()
{
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) {
            cin >> c;
            if(c == '.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    do {
        ok = 0;
        if(N > 1 && M > 1) {
        for(i = 1; i <= N; i++) {
                Ok = 1;
            for(j = 1; j < M && Ok == 1; j++)
                if(a[i][j] != a[i][j + 1] || a[i][j] != 1 && j > 1) Ok = 0;
            if(Ok == 1) {
                for(I = i; I < N; I++)
                    for(J = 1; J <= M; J++) a[I][J] = a[I + 1][J];
                N--;
                ok = 1;
                if(N == 1) ok = 0;
                break;
            }
        }
        }
    }
    while(ok == 1);
    if(N == 1 || M == 1) {
        if(N == 1) {
            for(i = 1; i <= M; i++) if(a[1][i] == 0) printf("#");
        }
        else if(M == 1)
            for(i = 1; i <= N; i++) if(a[i][1] == 0) printf("#");
            return 0;
    }
    do {
        ok = 0;
        if(N > 1 && M > 1) {
        for(j = 1; j <= M && ok == 0; j++) {
            Ok = 1;
            for(i = 1; i < N && Ok == 1 && ok == 0; i++)
                if(a[i][j] != a[i + 1][j] || a[i][j] != 1) Ok = 0;
            if(Ok == 1) {
                for(J = j; J < M; J++)
                    for(I = 1; I <= N; I++) a[I][J] = a[I][J + 1];
                ok = 1;
                M--;
                if(M == 1) ok = 0;
                break;
            }
        }
        }
    }
    while(ok == 1);
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) {
                if(a[i][j] == 1) printf(".");
                else printf("#");
        }
        printf("\n");
    }
    return 0;
}
