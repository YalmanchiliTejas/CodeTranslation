#include "bits/stdc++.h"
using namespace std;


int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int n = a * 100 + b * 10 + c;
    if (n % 4 == 0) puts("YES");
    else puts("NO");
}