#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void)
{
    int N, K;
    string S;
    cin >> N >> S >> K;
    auto c = S[K - 1];
    for (auto &i: S) if (i != c) i = '*';
    cout << S << endl;
    return 0;
}