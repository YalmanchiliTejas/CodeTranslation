#include <iostream>

using namespace std;

int main()
{
    int n, m, currMax = 0, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m >= currMax)
        {
            count++;
            currMax = m;
        }
    }
    cout << count;
}