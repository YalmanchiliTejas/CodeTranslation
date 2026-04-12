#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <numeric>
#include <sstream>
typedef long long ll;
using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    if (n == 7 || n == 5 || n == 3) {
        cout << "YES" << std::endl;
    } else {
        cout << "NO" << std::endl;
    }
    return 0;
}