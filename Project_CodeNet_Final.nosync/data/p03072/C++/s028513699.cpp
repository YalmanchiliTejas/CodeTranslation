#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

/* define const */
const long long INF = (1LL << 60);
/* end defineing */

int main()
{
    int n;
    int h[100];
    int count = 1;
    int highest = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    highest = h[0];
    for (int i = 1; i < n; i++)
    {
        if (h[i] >= highest)
        {
            count++;
            highest = h[i];
        }
    }
    cout << count << endl;
}
