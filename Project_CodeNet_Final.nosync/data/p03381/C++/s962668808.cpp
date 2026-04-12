#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct para
{
    int a, nr;
};

bool porownanie(para a, para b)
{
    if (a.a < b.a)
        return true;
    if (a.a > b.a)
        return false;
    if (a.nr < b.nr)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<para> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].a;
        a[i].nr = i;
    }
    sort(a.begin(), a.end(), porownanie);
    vector<int> odp(n);
    for (int i = 0; i < n; ++i)
    {
        if (i < n / 2)
            odp[a[i].nr] = a[n / 2].a;
        else
            odp[a[i].nr] = a[n / 2 - 1].a;
    }
    for (int i = 0; i < n; ++i)
        cout << odp[i] << " ";
    return 0;
}
