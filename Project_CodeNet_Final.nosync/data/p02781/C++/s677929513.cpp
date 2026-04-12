#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
using namespace std;

int nCk(int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    else if (k == 1)
    {
        return n;
    }
    else if (k == 2)
    {
        return n * (n - 1) / 2;
    }
    else if (k == 3)
    {
        return n * (n - 1) * (n - 2) / 6;
    }
    else
    {
        return 0;
    }
}

int DP(string n, int k)
{
    if (n.size() == 1)
    {
        if (k == 1)
        {
            return n[0] - '0';
        }
        else
        {
            return 0;
        }
    }
    if (k == 0)
    {
        return 1;
    }
    if (n[0] == '0')
    {
        return DP(n.substr(1), k);
    }

    int part = nCk(n.size() - 1, k) * pow(9, k) + nCk(n.size() - 1, k - 1) * pow(9, k - 1) * (n[0] - '0' - 1);
    return part + DP(n.substr(1), k - 1);
}

int main()
{
    string n;
    int k;
    cin >> n >> k;

    int ans = DP(n, k);
    cout << ans << endl;

    return 0;
}