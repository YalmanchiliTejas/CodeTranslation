//=================================
// Created on: 2018/09/20 10:58:25
//=================================
#include <bits/stdc++.h>
int main()
{
    int N, Q;
    std::cin >> N >> Q;
    int s = 0;
    for (int q = 0; q < Q; q++) {
        int t, k;
        std::cin >> t >> k;
        if (t == 0) {
            k--;
            std::cout << ((s + k) % N) + 1 << std::endl;
        } else {
            s = (s + k) % N;
        }
    }
    return 0;
}

