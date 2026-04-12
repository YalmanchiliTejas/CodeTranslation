// Great Ocean View

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int highest = h[0];
    int count = 0;

    for (int i = 1; i < n; i++) {
        if (h[i] == highest) {
            count++;
        } else if (h[i] > highest) {
            highest = h[i];
            count++;
        }
    }

    cout << count + 1 << endl;

    return 0;
}
