#include <iostream>
#include <cmath>
#include <map>
#include <utility>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define LL long long


int main() {
    int n;
    int max = 0;
    cin >> n;
    int total = 0;
    for (int i=0; i < n; i++) {
        int t;
        cin >> t;
        if (t >= max) {
            total++;
        }
        if (t > max) {
            max = t;
        }
    }

    cout << total << endl;
    return 0;
}