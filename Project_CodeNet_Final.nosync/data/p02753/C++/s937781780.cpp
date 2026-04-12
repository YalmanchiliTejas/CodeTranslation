#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <cmath>
using namespace std;

typedef long long llong;
typedef unsigned long long ullong;
// -2.1e-9 <= int <= 2.1e9
// 0 <= unsigned int <= 4.2e9

int main()
{
    string S; cin >> S;
    if ((S == "AAA") || (S == "BBB"))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

}
