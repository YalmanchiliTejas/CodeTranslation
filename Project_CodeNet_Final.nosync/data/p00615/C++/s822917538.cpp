#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<int> car(n+m+1);
        car[0] = 0;
        for (int i = 0; i < n+m; i++) {
            cin >> car[i+1];
        }
        sort(car.begin(), car.end());
        vector<int> interval;
        for (int i = 0; i < n+m; i++) {
            interval.push_back(car[i+1] - car[i]);
        }
        cout << *max_element(interval.begin(), interval.end()) << endl;
    }
    return 0;
}