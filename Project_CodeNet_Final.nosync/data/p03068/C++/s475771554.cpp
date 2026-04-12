#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N, K;
    string S;
    cin >> N >> S >> K;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] != S[K - 1])
        {
            S[i] = '*';
        }
    }
    cout << S << endl;
}
