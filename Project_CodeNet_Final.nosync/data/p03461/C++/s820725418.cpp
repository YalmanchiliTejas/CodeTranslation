#include <bits/stdc++.h>
using namespace std;
int A, B;
const int N = 15;
int dx[N][N], nw[N][N];
int V[N][N];
const int INF = 1e9 + 7;
vector <int> Ai, Bi, Ci;
void add_edge(int a, int b, int c)
{
    Ai.push_back(a);
    Bi.push_back(b);
    Ci.push_back(c);
}
int main()
{
    cin >> A >> B;
    for (int a = 1; a <= A; ++ a)
        for (int b = 1; b <= B; ++ b)
            cin >> dx[a][b], nw[a][b] = INF;
    for (int i = 1; i <= 100; ++ i)
        add_edge(i, i + 1, -1);
    for (int i = 1; i <= 100; ++ i)
        add_edge(101 + i, 101 + i + 1, -2);
    for (int i = 0; i <= 100; ++ i)
        for (int j = 0; j <= 100; ++ j)
        {
            int d = -INF;
            for (int a = 1; a <= A; ++ a)
                for (int b = 1; b <= B; ++ b)
                    d = max(d, dx[a][b] - (i * a + j * b));
            if (d >= 0 && d <= 100)
            {
                add_edge(i + 1, 202 - j, d);
                for (int a = 1; a <= A; ++ a)
                    for (int b = 1; b <= B; ++ b)
                        nw[a][b] = min(nw[a][b], i * a + j * b + d);
            }
        }
    for (int a = 1; a <= A; ++ a)
        for (int b = 1; b <= B; ++ b)
            if (nw[a][b] != dx[a][b])
                return cout << "Impossible" << endl, 0;
    cout << "Possible" << endl;
    cout << 202 << " " << Ci.size() << endl;
    for (int i = 0; i < Ci.size(); ++ i)
    {
        cout << Ai[i] << " " << Bi[i] << " ";
        if (Ci[i] == -1) cout << "X" << endl;
        else if (Ci[i] == -2) cout << "Y" << endl;
        else cout << Ci[i] << endl;
    }
    cout << 1 << " " << 202 << endl;
}
