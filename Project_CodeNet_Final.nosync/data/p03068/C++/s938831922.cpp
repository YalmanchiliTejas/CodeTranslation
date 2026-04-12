#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    char S[10];

    cin >> N;
    cin >> S;
    cin >> K;

    char k = S[K - 1];
    for (int i = 0; i < N; ++i)
    {
        if (S[i] != k)
        {
            cout << '*';
        }
        else
        {
            cout << S[i];
        }
    }

    cout << endl;

    return 0;
}
