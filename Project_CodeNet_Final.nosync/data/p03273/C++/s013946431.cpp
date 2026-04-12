#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> table(h);
    for (auto& v : table)
    {
        cin >> v;
    }

    set<int> rh, rw;
    for (int i = 0; i < h; i++)
    {
        int count = 0;
        for (int j = 0; j < w; j++)
        {
            if (table[i][j] == '#')
            {
                count++;
            }
        }
        if (count == 0)
        {
            rh.insert(i);
        }
    }
    for (int j = 0; j < w; j++)
    {
        int count = 0;
        for (int i = 0; i < h; i++)
        {
            if (table[i][j] == '#')
            {
                count++;
            }
        }
        if (count == 0)
        {
            rw.insert(j);
        }
    }

    for (int i = 0; i < h; i++)
    {
        if (rh.find(i) == rh.end())
        {
            for (int j = 0; j < w; j++)
            {
                if (rw.find(j) == rw.end())
                {
                    cout << table[i][j];
                }
            }
            cout << endl;
        }
    }
}
