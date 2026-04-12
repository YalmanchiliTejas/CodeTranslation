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

const int MAX_N = 100050;

long long A[MAX_N];
long long sgn1[MAX_N];
long long sgn2[MAX_N];
int N;

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        sgn1[i] = 0;
        sgn2[i] = 0;
    }

    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            sgn1[i-1]++;
            sgn1[i]--;

            sgn2[i-1]--;
            sgn2[i]++;
        } else {
            sgn1[i-1]--;
            sgn1[i]++;

            sgn2[i-1]++;
            sgn2[i]--;
        }
    }

    std::vector<long long> vec, sgn1_vec, sgn2_vec;

    for (int i = 1; i <= N; i++) {
        vec.push_back(A[i]);
        sgn1_vec.push_back(sgn1[i]);
        sgn2_vec.push_back(sgn2[i]);
    }

    std::sort(vec.begin(), vec.end());
    std::sort(sgn1_vec.begin(), sgn1_vec.end());
    std::sort(sgn2_vec.begin(), sgn2_vec.end());

    long long ret1 = 0;
    long long ret2 = 0;
    for (int i = 0; i < N; i++) {
        ret1 += sgn1_vec[i]*vec[i];
        ret2 += sgn2_vec[i]*vec[i];
    }

    std::cout << std::max(ret1, ret2) << std::endl;

    return 0;
}

