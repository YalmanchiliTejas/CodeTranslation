#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main() {
    int H;
    int W;
    scanf("%d %d", &H, &W);

    int ASTCOUNT = 0;

    char tmp[8];

    vector< vector<char> > A;
    vector< vector<int> > I;

    A.resize(H);
    I.resize(H);

    for (int i = 0; i < H; i++)
    {
        A[i].resize(W);
        I[i].resize(W);

        scanf("%s", tmp);

        for (int j = 0; j < strlen(tmp); j++)
        {
            A[i][j] = tmp[j];
            if (tmp[j] == '#') ASTCOUNT++;
        }
    }

    int y = 0;
    int x = 0;
    I[0][0] = 1;

    int STPCOUNT = 1;

    while (true)
    {
        if (x == W - 1 && y == H - 1)
        {
            if (A[y - 1][x] == '#' && I[y - 1][x] == 0)
            {
                printf("%s\n", "Impossible");
                return 0;
            }
            if (A[y][x - 1] == '#' && I[y][x - 1] == 0)
            {
                printf("%s\n", "Impossible");
                return 0;
            }
            break;
        }
        if (-1 < y - 1)
        {
            if (A[y - 1][x] == '#' && I[y - 1][x] == 0)
            {
                printf("%s\n", "Impossible");
                return 0;
            }
            I[y - 1][x] == 1;
        }
        if (-1 < x - 1)
        {
            if (A[y][x - 1] == '#' && I[y][x - 1] == 0)
            {
                printf("%s\n", "Impossible");
                return 0;
            }
            I[y][x - 1] = 1;
        }
        if (x + 1 < W)
        {
            I[y][x + 1] = 1;
            if (A[y][x + 1] == '#')
            {
                x = x + 1;
                STPCOUNT++;
                continue;
            }
        }
        if (y + 1 < H)
        {
            I[y + 1][x] = 1;
            if (A[y + 1][x] == '#')
            {
                y = y + 1;
                STPCOUNT++;
                continue;
            }
        }
        printf("%s\n", "Impossible");
        return 0;
    }

    if (ASTCOUNT == STPCOUNT)
    {
        printf("%s\n", "Possible");
        return 0;
    }
    else
    {
        printf("%s\n", "Impossible");
        return 0;
    }
}
