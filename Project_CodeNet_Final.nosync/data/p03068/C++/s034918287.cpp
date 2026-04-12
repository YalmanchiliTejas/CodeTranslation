#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N;
    string S;
    int K;
    char c;

    cin >> N >> S >>K;

    c = S[K-1];
    for (int i = 0; i < N; i++) {
        if (S[i] != c) {
            cout << "*";
        } else {
            cout << S[i];
        }
    }

    cout << endl;
    return 0;   
}