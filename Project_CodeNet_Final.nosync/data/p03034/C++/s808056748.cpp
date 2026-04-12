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

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

const int MAX_N = 100050;
int N;
int S[MAX_N];

std::unordered_map<int, long long> dp[MAX_N];
long long NEG_INF = -(long long)100000000000000;

long long func(int sub, int k) {
    int A = N - 1 - k * sub;
    if (A <= 1) {
        return NEG_INF;
    }
    if (A - sub <= 0) {
        return NEG_INF;
    }
    if (A % sub == 0 && A*2 <= N - 1) {
        return NEG_INF;
    }

    if (k == 0) {
        return 0;
    }

    if (dp[sub].find(k) != dp[sub].end()) {
        return dp[sub][k];
    }

    long long ret;
    if (k*sub != N-1-k*sub) {
        ret = func(sub, k - 1) + S[k*sub] + S[N-1-k*sub];
    } else {
        ret = NEG_INF;
    }

    //long long ret = func(sub, k - 1) + S[k*sub] + S[N-1-k*sub];

    dp[sub][k] = ret;
    return ret;
}

int score[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 0; i <= N - 1; i++) {
        std::cin >> S[i];
    }

    long long ret = 0;
    for (int sub = 1; sub <= N; sub++) {
        for (int k = 0; k*sub < N - 1; k++) {
            ret = std::max(ret, func(sub, k));
        }
    }

    std::cout << ret << std::endl;

    return 0;
}