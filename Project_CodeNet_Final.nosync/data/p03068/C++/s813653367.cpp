#include <iostream>

using namespace std;

int main()
{
    int N, K;
    string S;

    cin >> N;
    cin >> S;
    cin >> K;

    char target = S[K-1];

    for (int i = 0; i < N; i++)
    {
        if (target == S[i])
        {
            cout << target;
        }
        else
        {
            cout << "*";
        }
    }

    cout << endl;

    return 0;
}