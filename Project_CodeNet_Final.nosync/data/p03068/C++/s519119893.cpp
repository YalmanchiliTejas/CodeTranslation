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

std::string S;
int N, K;
 
int main(int argc, char **argv) {
    std::cin >> N;
    std::cin >> S;
    std::cin >> K;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != S[K-1]) {
            S[i] = '*';
        }
    }
    std::cout << S << std::endl;

    return 0;
}