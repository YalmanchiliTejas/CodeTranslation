#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include <cstring>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    double R1, R2;
    cin >> R1 >> R2;
    printf("%.10lf\n",  R1 * R2 / (R1 + R2));
}
