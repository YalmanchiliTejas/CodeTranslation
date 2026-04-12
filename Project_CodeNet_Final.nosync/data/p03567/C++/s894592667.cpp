#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;


int main() {
    struct timeval start,end;
    long long span;
    string s;

    gettimeofday(&start,NULL);

    std::cin >> s;
    bool flag = true;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'C') {
            std::cout << "Yes" << std::endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "No" << std::endl;
    }

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
