#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>
#include <iomanip>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if ((a*100 + b*10 + c) % 4) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}
