#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    int N, K;
    cin >> N;
    cin >> S;
    cin >> K;
    char trans = S[K - 1];
    for (int i = 0; i < N; i++)
    {
        if (S[i] != trans)
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