#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    string S;
    cin >> N >> S >> K;
    char c = S[K - 1];

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != c)
        {
            cout << "*";
        }
        else
        {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}