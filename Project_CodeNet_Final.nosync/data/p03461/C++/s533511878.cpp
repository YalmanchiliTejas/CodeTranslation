#include <bits/stdc++.h>
using namespace std;

int a, b;
vector<vector<int> > d;

int saitan(vector<vector<pair<int, int> > > edges)
{
    vector<int> dist_tmp(202, 101);
    dist_tmp[0] = 0;

    for (int i=0; i<201; i++)
    {
        for (auto to : edges[i])
        {
            dist_tmp[to.first] = min(dist_tmp[to.first], dist_tmp[i] + to.second);
        }
    }
    return dist_tmp[201];
}

int main()
{
    cin >> a >> b;
    d = vector<vector<int> >(a, vector<int>(b, 0));

    for (int i=0; i<a; i++) for (int j=0; j<b; j++) cin >> d[i][j];

    vector<vector<int> > length(101, vector<int>(101, 0));
    for (int ii=0; ii<a; ii++)
        for (int jj=0; jj<b; jj++)
            for (int i=0; i<=100; i++)
                for (int j=0; j<=100; j++)
                    length[i][j] = max(length[i][j], d[ii][jj] - i * (ii+1) - j * (jj+1));

    vector<vector<pair<int, int> > > edge(201);
    for (int i=0; i<=100; i++)
    {
        for (int j=0; j<=100; j++)
        {
            edge[i].push_back(make_pair(201-j, length[i][j]));
        }
    }

    for (int x=1; x<=a; x++)
    {
        for (int y=1; y<=b; y++)
        {
            vector<vector<pair<int, int> > > edge_copy = edge;
            for (int i=0; i<100; i++)
            {
                edge_copy[i].push_back(make_pair(i+1, x));
                edge_copy[101+i].push_back(make_pair(i+102, y));
            }
            if (saitan(edge_copy) != d[x-1][y-1])
            {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;

    cout << "202 10401" << endl;
    for (int i=1; i<=100; i++)
    {
        cout << i << " " << i+1 << " X" << endl;
        cout << i+101 << " " << i+102 << " Y" << endl;
    }
    for (int i=0; i<=100; i++)
    {
        for (int j=0; j<=100; j++)
        {
            cout << i+1 << " " << 202-j << " " << length[i][j] << endl;
        }
    }
    cout << "1 202" << endl;
    return 0;
}