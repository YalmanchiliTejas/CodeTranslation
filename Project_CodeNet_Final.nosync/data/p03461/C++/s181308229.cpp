#include <bits/stdc++.h>

#define AB_MAX 12
#define N_MAX 102

using namespace std;

int A, B;

int d[AB_MAX][AB_MAX];

int a[N_MAX][N_MAX];

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    bool ok = true;
    for(int i = 1; i <= A; i++)
        for(int j = 1; j <= B; j++)
        {
            cin >> d[i][j];
            if(d[i][j] < d[i - 1][j] || d[i][j] < d[i][j - 1])
                ok = false;
        }
    if(ok == false)
    {
        cout << "Impossible\n";
        return 0;
    }
    n = 101;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
        {
            for(int x = 1; x <= A; x++)
                for(int y = 1; y <= B; y++)
                    a[i][j] = max(a[i][j], d[x][y] - x * i - y * j);
        }
    for(int x = 1; x <= A; x++)
        for(int y = 1; y <= B; y++)
        {
            int mi = 1e9+1;
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++)
                    mi = min(mi, a[i][j] + x * i + y * j);
            if(mi != d[x][y])
            {
                cout << "Impossible\n";
                return 0;
            }
        }
    int cntX = 101;
    int cntY = 101;
    cout << "Possible\n";
    cout << cntX + cntY + 2 << " " << cntX - 1 + cntY - 1 + cntX * cntY + 2 << "\n";
    for(int i = 2; i < cntX + 1; i++)
        cout << i << " " << i + 1 << " X\n";
    for(int i = 2; i < cntY + 1; i++)
        cout << cntX + i << " " << cntX + i + 1 << " Y\n";
    cout << "1 2 0\n";
    for(int i = 2; i <= cntX + 1; i++)
        for(int j = 2; j <= cntY + 1; j++)
            cout << i << " " << cntX + j << " " << a[i - 2][cntY - j + 1] << "\n";
    cout << cntX + cntY + 1 << " " << cntX + cntY + 2 << " 0\n";
    cout << 1 << " " << cntX + cntY + 2 << "\n";
    return 0;
}
