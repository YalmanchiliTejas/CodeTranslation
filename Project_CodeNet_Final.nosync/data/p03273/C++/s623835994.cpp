#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a;
    for (int i = 0; i < h; i++)
    {
        string stg;
        cin >> stg;
        if (count(stg.begin(), stg.end(), '.') < w)
        {
            a.push_back(stg);
        }
    }
    h = a.size();
    for (int i = 0; i < w; i++)
    {
        int siro = 0;
        for (int j = 0; j < h; j++)
        {
            if (a.at(j)[i] == '.')
            {
                siro++;
            }
        }
        if (siro == h)
        {
            for (int j = 0; j < h; j++)
            {
                a.at(j).erase(a.at(j).begin() + i);
            }
            i--;
            w--;
        }
    }
    for (int i = 0; i < h; i++)
    {
        cout << a.at(i) << endl;
    }
}