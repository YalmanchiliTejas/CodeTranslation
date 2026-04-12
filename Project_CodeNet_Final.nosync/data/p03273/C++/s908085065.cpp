#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reprev(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<char>> arr(h, vector<char>(w, '-'));
    vector<bool> ho(w, true);
    vector<bool> va(h, true);

    rep(i, h)
    {
        string str;
        cin >> str;
        rep(j, w)
        {
            arr.at(i).at(j) = str[j];
        }
    }

    rep(i, h)
    {
        rep(j, w)
        {
            if (arr.at(i).at(j) == '.')
            {
                if (j == (w - 1))
                    va.at(i) = false;
            }
            else
                break;
        }
    }

    rep(j, w)
    {
        rep(i, h)
        {
            if (arr.at(i).at(j) == '.')
            {
                if (i == (h - 1))
                    ho.at(j) = false;
            }
            else
                break;
        }
    }

    rep(i, h)
    {

        if (!va.at(i))
            continue;
        rep(j, w)
        {
            if (ho.at(j))
            {
                cout << arr.at(i).at(j);
            }
        }
        cout << endl;
    }
}
