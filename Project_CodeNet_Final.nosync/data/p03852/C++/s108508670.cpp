#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>
#include <cstring>

#define INF 100000000

using namespace std;

int main()
{
    char a;
    cin >> a;
    if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')
        cout << "vowel\n";
    else
        cout << "consonant\n";
    return 0;
}
