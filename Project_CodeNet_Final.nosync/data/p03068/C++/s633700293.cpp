#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
#define umap unordered_map
const static ull INVALID_DIGIT = ~(ull)0;

int main()
{
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;

    char targetChar = S[K - 1];

    for (size_t i = 0; i < N; i++) {
        if (S[i] != targetChar) {
            S[i] = '*';
        }
    }
    cout << S << endl;

    return 0;
}