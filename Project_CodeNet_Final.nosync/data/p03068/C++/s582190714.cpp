#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    string S;
    cin >> N >> S >> K;

    vector<int> s(N);

    int safe = S[K - 1];

    for (int n = 0; n < N; n++)
    {
        s[n] = S[n];
        if (s[n] == safe)
            cout << S[n];
        else
        {
            cout << '*';
        }
    }

    return 0;
}