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
#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

const int MAX_N = 65;
const long long MAX_VAL = (long long)10000000000000000 + 1000;

long long a[MAX_N];
long long mod[MAX_N];
int N;
long long last[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    long long sum = 0;
    bool is0 = true;
    for (int i = 1; i <= N; i++) {
        mod[i] = a[i] % (N + 1);
        sum += a[i];
        if (N - 1 < a[i]) {
            is0 = false;
        }
    }

    if (is0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long ret = MAX_VAL * MAX_N;
    for (int i = 1; i <= N; i++) {
        long long sum_tmp = 0;
        for (int j = 1; j <= N; j++) {
            last[j] = N - 1 + mod[j] - mod[i];
            while (N - 1 < last[j]) {
                last[j] -= (N + 1);
            }
            sum_tmp += last[j];
        }
        if (sum_tmp < sum) {
            ret = std::min(ret, std::max(sum - sum_tmp, (long long)0));
        }
        //std::cout << i << " " << sum_tmp << std::endl;
        //ret = std::min(ret, std::max(sum - sum_tmp, (long long)0));
    }

    std::cout << ret << std::endl;
    return 0;

}