#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int a[100'000];
int lowest[100'000];

int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cols = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int ub = cols;
        int lb = -1;
        while (lb + 1 < ub)
        {
            int mid = (ub + lb) / 2;

            if (lowest[mid] > a[i])
            {
                ub = mid;
            }
            else
            {
                lb = mid;
            }
        }

        if (ub < cols)
        {
            lowest[ub] = a[i];
        }
        else
        {
            lowest[cols++] = a[i];
        }
    }

    cout << cols << endl;

    return 0;
}