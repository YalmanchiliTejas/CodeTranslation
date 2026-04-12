#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<string> vec(a);
    rep(i, a) cin >> vec[i];

    vector<int> yoko(a, 0);
    vector<int> tate(b, 0);

    rep(i, a)
    {
        rep(j, b)
        {
            if (vec[i][j] == '#')
            {
                yoko[i]++;
                tate[j]++;
            }
        }
    }

    rep(i, a)
    {
        if (yoko[i])
        {
            rep(j, b)
            {
                if (tate[j])
                {
                    cout << vec[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
