#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    long long n, x, res = 0;
    vector<long long> burgerBuns(51);
    vector<long long> burgerPatty(51);

    cin >> n >> x;

    burgerBuns[0] = 1;
    burgerPatty[0] = 1;

    for (long long i = 1; i <= 50; ++i)
    {
        burgerBuns[i] = burgerBuns[i - 1] * 2 + 3;
        burgerPatty[i] = burgerPatty[i - 1] * 2 + 1;
    }

    while (n > 0 && x > 0)
    {
        x--;
        n--;
        if (x >= burgerBuns[n])
        {
            x -= burgerBuns[n];
            res += burgerPatty[n];
            if (x == 0)
            {
                break;
            }
            x--;
            res++;
            if (x >= burgerBuns[n])
            {
                res += burgerPatty[n];
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}