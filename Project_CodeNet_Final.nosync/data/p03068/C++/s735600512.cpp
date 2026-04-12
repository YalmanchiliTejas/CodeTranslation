#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S;
    int N, K;
    cin >> N >> S >> K;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == S[K - 1])
        {
            cout << S[i];
        }
        else
        {
            cout << "*";
        }
    }
}