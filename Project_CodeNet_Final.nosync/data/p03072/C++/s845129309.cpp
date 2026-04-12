#include <iostream>

#define REP(i, N) for (int i = 0; i < N; ++i)

using namespace std;

int main()
{
    int n;
    int h[20];
    cin >> n;
    REP(i, n)
        cin >> h[i];

    int t = 0;
    int count = 0;
    REP(i, n)
        if (h[i] >= t)
        {
            ++count;
            t = h[i];
        }

    cout << count << endl;
    return 0;
}