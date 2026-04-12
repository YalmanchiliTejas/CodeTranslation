#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, K;
    string S;

    cin >> N >> S >> K;

    char ch = S[K-1];

    for (int i = 0; i < S.length(); i++) {
        if (S[i] != ch) {
            S[i] = '*';
        }
    }

    cout << S << endl;
    return 0;
}
