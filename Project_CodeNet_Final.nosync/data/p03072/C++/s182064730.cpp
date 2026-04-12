#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int H[N];
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    int c = 1;
    int m = H[0];
    for (int i = 1; i < N; i++)
    {
        if (m <= H[i]) {
            c++;
        }

        m = max(m, H[i]);
    }

    cout << c << endl;

    return 0;
}