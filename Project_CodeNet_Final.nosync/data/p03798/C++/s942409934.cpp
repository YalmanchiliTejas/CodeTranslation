#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MOD int(1e9 + 7)

int main()
{
    long long N;
    string S;

    cin >> N;
    cin >> S;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            vector<int> o(N + 1, -1);
            bool f = false;
            o[0] = i;
            o[1] = j;
            for (int k = 1; k < N + 200; k++)
            {
                int t;
                if (S[k % N] == 'o')
                    t = o[k % N] == 0 ? o[(k - 1) % N] : 1 - o[(k - 1) % N];
                else
                    t = o[k % N] == 0 ? 1 - o[(k - 1) % N] : o[(k - 1) % N];

                if (o[(k + 1) % N] != -1 && o[(k + 1) % N] != t)
                {
                    f = true;
                    break;
                }

                o[(k + 1) % N] = t;
            }
            if (f == false)
            {
                for (int l = 0; l < N; l++)
                {
                    if (o[l] == 0)
                        cout << 'S';
                    else
                        cout << 'W';
                }
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}