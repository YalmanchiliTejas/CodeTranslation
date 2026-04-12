#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n;i++)

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
