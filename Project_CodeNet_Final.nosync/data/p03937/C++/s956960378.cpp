#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <sstream>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    int h, w;
    std::cin >> h >> w;
    vector<vector<char>> a(h);
    int count = 0;
    for (int i = 0; i < h; i++) {
        a[i].resize(w);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') count++;
        }
    }
    if (count > h+w-1) {
        std::cout << "Impossible" << std::endl;
    } else {
        std::cout << "Possible" << std::endl;
    }
    return 0;
}