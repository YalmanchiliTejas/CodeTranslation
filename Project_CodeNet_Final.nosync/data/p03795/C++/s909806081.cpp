#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t N;
    cin >> N;
    int64_t r = N * 800;
    int64_t s = (N / 15) * 200;
    cout << r - s << endl;
    return 0;
}