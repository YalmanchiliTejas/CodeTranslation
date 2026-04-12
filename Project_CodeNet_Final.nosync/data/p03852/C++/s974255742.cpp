#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <regex>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    char c;
    cin >> c;
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
        if (c == v[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}
