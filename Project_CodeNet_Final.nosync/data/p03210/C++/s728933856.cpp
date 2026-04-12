#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define N_MAX   (100000)
#define LL_MAX_NUM (1LL<<60)

typedef long long ll;

int main() {
    
    int X;
    cin >> X;
    if (X == 7 || X == 5 || X== 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}