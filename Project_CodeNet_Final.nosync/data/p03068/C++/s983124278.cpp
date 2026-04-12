#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int N, K;
    string S;
    cin >> N >> S >> K;

    char target = S.at(K-1);

    for (int i = 0; i < N; i++)
    {
        if (S.at(i) == target)
            cout << target;
        else
            cout << '*';
    }
}