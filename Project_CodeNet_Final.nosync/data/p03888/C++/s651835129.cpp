#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("%.9lf\n", a * b / (a + b));
        return 0;
}

