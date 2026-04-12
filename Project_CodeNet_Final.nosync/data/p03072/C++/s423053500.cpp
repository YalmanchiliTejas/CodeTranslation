#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, h[110];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int count = 1;
    int maxh = h[0];

    for (int i = 1; i < n; i++)
    {
        maxh = max(h[i], maxh);
        if (h[i] - maxh >= 0)
            count++;
    }

    cout << count << endl;

    return 0;
}
