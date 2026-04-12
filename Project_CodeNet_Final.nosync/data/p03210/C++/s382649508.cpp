#include <bits/stdc++.h>
using namespace std;

int main() {
    uint_fast64_t N;
    cin >> N;
    puts((N ^ 1) && ((N | 6) == 7) ? "YES" : "NO");
    return 0;
}