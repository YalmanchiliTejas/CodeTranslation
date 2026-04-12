#include <bits/stdc++.h>

using namespace std;

int main () {
double r1, r2;

cin >> r1 >> r2;

r1 = 1/r1, r2 = 1/r2;

cout  << fixed << setprecision (6) << 1 / (r1 + r2);


return 0;
}
