#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int res = 0;
    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (h >= maxHeight) {
            ++res;
            maxHeight = h;
        }
    }
    cout << res << endl;
}
