#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>

using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
    ll h, w;
    cin >> h >> w;
    vector<string> s;
    for (ll i = 0; i < h; i++)
    {
        string t;
        cin >> t;
        s.push_back(t);
    }

    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i].find('#') == -1) {
            s.erase(s.begin() + i);
            i--;
        }
    }

    for (ll i = 0; i < w; i++)
    {
        bool tt = false;
        for (ll t = 0; t < s.size(); t++)
        {
            if(s[t][i] == '#'){
                tt = true;
                break;
            }
        }

        if (!tt)
        {
            for (ll k = 0; k < s.size(); k++)
            {
                s[k].erase(i, 1);
            }
            i--;
            w--;
        }
    }

    for (ll i = 0; i < s.size(); i++)
    {
        cout << s[i] << endl;
    }
}