#include<bits/stdc++.h>

using namespace std;

int N, M;
char sir[509][509];
bool ap[509][509];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void fill (int i, int j)
{
    if (ap[i][j]) return ;
    ap[i][j] = 1;
    for (int k=0; k<4; k++)
        if (sir[i + dx[k]][j + dy[k]] == '#')
            fill (i + dx[k], j + dy[k]);
}

void Ans (bool val)
{
    if (val) printf ("Possible\n");
    else printf ("Impossible\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%s", sir[i] + 1);
/*if (sir[1][1] != '#' || sir[N][M] != '#') Ans (0);
fill (1, 1);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] == '#' && ap[i][j] == 0)
            Ans (0);
Ans (1);*/
int i = 1, j = 1;
while (i < N || j < M)
{
    ap[i][j] = 1;
    if (sir[i][j + 1] == '#') j ++;
    else
    if (sir[i + 1][j] != '#') Ans (0);
    else i ++;
}
ap[i][j] = 1;
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] == '#' && ap[i][j] == 0)
            Ans (0);
Ans (1);
return 0;
}
