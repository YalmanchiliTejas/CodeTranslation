#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print_vec(std::vector<bool> &v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<bool> ho(h, false), vi(w, false);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (v[i][j] == '#')
            {
                ho[i] = true;
            }
        }
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (v[j][i] == '#')
            {
                vi[i] = true;
            }
        }
    }
    //     for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         {
    //             cout << v[i][j];
    //         }
    //     }
    //     cout << endl;
    // }
    bool check;
    for (int i = 0; i < h; i++)
    {
        check = false;
        for (int j = 0; j < w; j++)
        {
            if (ho[i] && vi[j])
            {
                check = true;
                cout << v[i][j];
            }
        }
        if (check)
        cout << endl;
    }
    return 0;
}
