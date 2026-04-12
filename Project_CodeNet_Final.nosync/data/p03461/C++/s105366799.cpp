#include <iostream>
#include <vector>
using namespace std;
int N;
int A, B;
int Matrix[15][15];
vector <pair <int, int> > G[100005];
int D[15][15], Cost[305][305];
int cnt;
void Read()
{
    cin >> A >> B;
    for(int i = 1; i <= A; i++)
        for(int j = 1; j <= B; j++)
            cin >> Matrix[i][j];
}

void precalcG()
{
    cnt = 1;
    int last = 1;
    int lastS, M = 0;
    for(int i = 1; i <= 101; i++)
    {
        ++cnt;
        G[last].push_back(make_pair(cnt, -1));
        ++M;
        last = cnt;
        lastS = cnt;
    }
    ++cnt;
    last = cnt;
    ++cnt;
    G[last].push_back(make_pair(cnt, -2));
    ++M;
    for(int i = 2; i <= 101; i++)
    {
        ++cnt;
        G[last].push_back(make_pair(cnt, -2));++M;
        last = cnt;
    }
    for(int i = 1; i <= lastS; i++)
    {
        for(int j = lastS + 1; j <= cnt; j++)
        {
            int coefx = i - 1, coefy = cnt - j;
            int val = 0;
            for(int a = 1; a <= A; a++)
                for(int b = 1; b <= B; b++)
                    val = max(val, max(0, Matrix[a][b] - coefx * a - coefy * b));
            Cost[i][j] = val;
            G[i].push_back(make_pair(j, val));++M;
        }
    }
    for(int a = 1; a <= A; a++)
        for(int b = 1; b <= B; b++)
    {
        D[a][b] = 105;
        for(int i = 1; i <= lastS; i++)
            for(int j = lastS + 1; j <= cnt; j++)
            {
                int coefx = i - 1, coefy = cnt - j;
                D[a][b] = min(D[a][b], coefx * a + coefy * b + Cost[i][j]);
            }
        if(D[a][b] != Matrix[a][b])
        {
            cout << "Impossible\n";
            return;
        }
    }
    cout << "Possible\n";
    cout << cnt << " " << M << "\n";
    for(int i = 1; i <= cnt; i++)
        for(int j = 0; j < G[i].size(); j++)
        {
            int neighb = G[i][j].first, val = G[i][j].second;
            cout << i << " " << neighb << " ";
            if(val >= 0)
                cout << val;
            if(val == -1)
                cout << "X";
            if(val == -2)
                cout << "Y";
            cout << "\n";
        }
    cout << "1 " << cnt << '\n';
}
int main()
{
    Read();
    precalcG();
    return 0;
}
