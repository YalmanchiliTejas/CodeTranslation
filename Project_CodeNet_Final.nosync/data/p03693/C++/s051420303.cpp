#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <limits>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    if (stoi(a + b + c)  % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}