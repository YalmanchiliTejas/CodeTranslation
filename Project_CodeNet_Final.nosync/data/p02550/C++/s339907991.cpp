#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    long long int n, x, m;
    cin >> n >> x >> m;
    long long int res = 0;
    unordered_map<long long int, int> um;
    long long int index = 1;
    vector<long long int> v(1, 0);
    while (index <= n) {
        if (um.find(x) == um.end()) {
            um[x] = index;
            index++;
            v.push_back(x);
        } else {
            long long int cir = (n - index + 1) / (index - um[x]);
            long long int loop = index - um[x];
            long long int loop_sum = 0;
            for (int i = 0; i < loop; i++) {
                loop_sum += v[v.size() - 1 - i];
            }
            res += loop_sum * cir;
            index = cir * loop + index;
            break;
        }
        res += x;
        x = x * x % m;
    }
    while (index <= n) {
        res += x;
        index++;
        x = x * x % m;
    }
    cout << res << endl;
}




