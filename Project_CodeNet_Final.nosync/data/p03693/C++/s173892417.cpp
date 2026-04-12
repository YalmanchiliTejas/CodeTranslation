#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int x = a * 100 + b * 10 + c;
    if (x % 4 == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
