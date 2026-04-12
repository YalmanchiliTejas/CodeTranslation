#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};

struct pkt
{
    int x, y;
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    pkt akt = {0, 0};
    a[0][0] = 'x';
    while (true)
    {
        bool dalej;
        for (int i = 0; i < 2; ++i)
        {
            dalej = false;
            pkt nowy = {akt.x + dx[i], akt.y + dy[i]};
            if (nowy.x >= 0 && nowy.x < n && nowy.y >= 0 && nowy.y < m)
            {
                if (a[nowy.x][nowy.y] == '#')
                {
                    a[nowy.x][nowy.y] = 'x';
                    akt = nowy;
                    dalej = true;
                    break;
                }
            }
        }
        if (!dalej)
            break;
    }
    bool db = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '#')
                db = false;
    if (db)
        cout << "Possible";
    else
        cout << "Impossible";
    return 0;
}
