#include<bits/stdc++.h>

using namespace std;

int nr, N, A, B, d[15][15], mi[109][109], cod[2][109];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &A, &B);
for (int x=1; x<=A; x++)
    for (int y=1; y<=B; y++)
    {
        scanf ("%d", &d[x][y]);
        for (int i=0; i<=100; i++)
            for (int j=0; j<=100; j++)
            {
                int curr = d[x][y] - x * i - y * j;
                if (curr > mi[i][j])
                    mi[i][j] = curr;
            }
    }
for (int x=1; x<=A; x++)
    for (int y=1; y<=B; y++)
    {
        int mini = 1 << 30;
        for (int i=0; i<=100; i++)
            for (int j=0; j<=100; j++)
            {
                int curr = mi[i][j] + i * x + j * y;
                if (curr < mini)
                    mini = curr;
            }
        if (mini != d[x][y])
        {
            printf ("Impossible\n");
            return 0;
        }
    }
for (int i=0; i<2; i++)
    for (int j=0; j<=100; j++)
        cod[i][j] = ++nr;
printf ("Possible\n");
printf ("%d %d\n", nr, 101 * 101 + 200);
for (int i=0; i<2; i++)
{
    char c = (i == 0 ? 'X' : 'Y');
    for (int j=1; j<=100; j++)
        printf ("%d %d %c\n", cod[i][j - 1], cod[i][j], c);
}
for (int i=0; i<=100; i++)
    for (int j=0; j<=100; j++)
        printf ("%d %d %d\n", cod[0][i], cod[1][100 - j], mi[i][j]);
printf ("%d %d\n", cod[0][0], cod[1][100]);
return 0;
}
