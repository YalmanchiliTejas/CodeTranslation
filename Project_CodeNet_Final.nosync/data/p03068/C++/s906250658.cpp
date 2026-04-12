#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;
    int K;
    cin >> N >> S >> K;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != S[K-1])
        {
            S[i] = '*';
        }
    }
    cout << S << endl;
    return 0;
}