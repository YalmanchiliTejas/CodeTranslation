#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    
    int N,M;
    cin >> N >> M;
    string out = "No";
    if(N == M) out = "Yes";
    cout << out << endl;
    return 0;
}
