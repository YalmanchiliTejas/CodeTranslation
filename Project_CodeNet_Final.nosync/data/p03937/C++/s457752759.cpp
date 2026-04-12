#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;

int main() {
    int H, W;
    cin >> H >> W;
    string A;
    int sum = 0;
    for (int i = 0; i < H; i++) {
        cin >> A;
        for (int j = 0; j < W; j++) {
            if (A[j] == '#') {
                sum++;
            }
        }   
    }
    if (sum == H + W - 1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
