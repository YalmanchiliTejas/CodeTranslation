#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int CMax = 100002;

int n, A, B, C, ats;

int main() {
    scanf("%d %d %d", &A, &B, &C);

    ats = A / (B + C);
    if (A % (B+C) >= C) cout << ats << endl;
    else cout << max(ats - 1, 0) << endl;
}
