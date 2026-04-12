#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int x, y, z;
int main(int argc, char const *argv[])
{
    cin >> x >> y >> z;
    cout << (x - z) / (y + z) << endl;

    return 0;
}