#include "bits/stdc++.h"
using namespace std;

int main() {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int w = y + z;
        x -= z;
        printf("%d\n", x / w);
        return 0;
}

