#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    string S;
    int K;

    cin >> N;
    cin >> S;
    cin >> K;

    char kth_S = S[K - 1];

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != kth_S)
        {
            S[i] = '*';
        }
    }

    cout << S;

    return 0;
}
