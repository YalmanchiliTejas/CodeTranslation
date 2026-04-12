#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    int max_height = 0;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h = 0;
        cin >> h;
        if (h >= max_height) {
            max_height = h;
            sum++;
        }
    }
    cout << sum;
}
