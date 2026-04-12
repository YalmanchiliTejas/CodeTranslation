#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>
#include <unordered_map>

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;

    string S;
    cin >> S;

    int K;
    cin >> K;

    char target = S[K-1];

    for (const auto& c : S) {
        if (c != target) {
            cout << "*";
        } else {
            cout << c;
        }
    }

    cout << endl;

    return 0;
}
