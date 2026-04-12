#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

const int MAX_N = 200;
int N;
int H[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> H[i];
    }

    int cond = 0;
    int num = 0;

    for (int i = 1; i <= N; i++) {
        if (cond <= H[i]) {
            num++;
            cond = H[i];
        }
    }

    std::cout << num << std::endl;
    return 0;
}
