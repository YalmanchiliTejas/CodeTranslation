#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define repi(i, a, b) for (long long i = (long long)(a); i < (long long)(b); i++)
#define drep(i, n) for (long long i = n - 1; i > 0; i--)
#define pb push_back
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++)
    {
        cin >> a[i];
    }

    vector<bool> row(h, false), col(w, false);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == '#')
            {
                col[j] = true;
                row[i] = true;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        if (row[i] == true)
        {
            for (int j = 0; j < w; j++)
            {
                if (col[j] == true)
                {
                    cout << a[i][j];
                }
            }
            cout << "\n";
        }
    }
    return 0;
    /* ABC 031 A
    int a, b,a_plus_ans,b_plus_ans;
    cin >> a >> b;

    b_plus_ans = (b+1)*a;
    a_plus_ans = (a+1)*b;

    if (a_plus_ans >= b_plus_ans)
    {
        cout << (a + 1) * b << endl;
    }
    else
    {
        cout << (b + 1) * a << endl;
    }

    return 0;*/
}