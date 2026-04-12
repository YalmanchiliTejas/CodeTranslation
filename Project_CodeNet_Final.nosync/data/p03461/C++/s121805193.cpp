#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

#define int long long

const int MOD = 1e9 + 7;

int a, b;
int d[50][50];
int go[200][200];

signed main()
{
    //freopen("input_02.txt", "r", stdin);
    //freopen("output_02.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            int max_c = -1e9;
            for (int x = 1; x <= a; x++)
            {
                for (int y = 1; y <= b; y++)
                {
                    int moved = i * x + j * y;
                    int add = d[x][y] - moved;
                    max_c = max(max_c, add);
                }
            }
            if (max_c <= 100 && 0 <= max_c)
            {
                go[i][j] = max_c;
            }
            else
            {
                go[i][j] = 1e9;
            }
        }
    }
    for (int x = 1; x <= a; x++)
    {
        for (int y = 1; y <= b; y++)
        {
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    if (x * i + go[i][j] + y * j < d[x][y])
                    {
                        go[i][j] = 1e9;
                    }
                }
            }
        }
    }
    for (int x = 1; x <= a; x++)
    {
        for (int y = 1; y <= b; y++)
        {
            int min_c = 1e9;
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    if (min_c > i * x + go[i][j] + j * y)
                    {
                        min_c = i * x + go[i][j] + j * y;
                    }
                }
            }
            if (min_c != d[x][y])
            {
                cout << "Impossible";
                return 0;
            }
        }
    }
    cout << "Possible\n";
    int cnt = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (go[i][j] <= 100 && 0 <= go[i][j]) cnt++;
        }
    }
    cout << 202 << " " << cnt + 200 << "\n";
    for (int i = 0; i < 100; i++)
    {
        cout << i + 1 << " " << i + 2 << " " << 'X' << "\n";
    }
    for (int j = 0; j < 100; j++)
    {
        cout << 202 - j - 1 << " " << 202 - j << " " << 'Y' << "\n";
    }
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (go[i][j] <= 100 && 0 <= go[i][j])
            {
                cout << i + 1 << " " << 202 - j << " " << go[i][j] << "\n";
            }
        }
    }
    cout << 1 << " " << 202 << "\n";
}
