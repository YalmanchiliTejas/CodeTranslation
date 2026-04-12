#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string n;
    int k;
    cin >> n >> k;
    int odp = 0;
    for (int d = 1; d <= (int) n.size() - 1; ++d)
    {
        if (d < k)
            continue;
        if (k == 1)
            odp += 9;
        if (k == 2)
            odp += (d - 1) * 9 * 9;
        if (k == 3)
            odp += (d - 1) * (d - 2) / 2 * 9 * 9 * 9;
    }
    int nz = 0;
    for (int i = 0; i < n.size(); ++i)
    {
        for (int c = (i == 0) ? 1 : 0; c < n[i] - '0'; ++c)
        {
            int r = (int) n.size() - i - 1;
            if (nz + (c != 0) > k)
                continue;
            int moge = k - (nz + (c != 0));
            if (r < moge)
                continue;
            if (moge == 0)
                ++odp;
            if (moge == 1)
                odp += r * 9;
            if (moge == 2)
                odp += r * (r - 1) / 2 * 9 * 9;
        }
        if (n[i] != '0')
            ++nz;
    }
    nz = 0;
    for (int i = 0; i < n.size(); ++i)
        nz += (n[i] != '0');
    if (nz == k)
        ++odp;
    cout << odp;
    return 0;
}
