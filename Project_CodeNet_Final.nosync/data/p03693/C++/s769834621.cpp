#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    char r, g, b;
    cin >> r >> g >> b;
    string temp;
    temp += r;
    temp += g;
    temp += b;
    if (stoi(temp) % 4 == 0) cout << "YES"; else cout << "NO";
}