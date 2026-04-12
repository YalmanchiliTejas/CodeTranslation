#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main(void) {
    int x, y, z;
    std::scanf("%d %d %d", &x, &y, &z);
    std::printf("%d\n", (x - z) / (y + z));
    return 0;
}