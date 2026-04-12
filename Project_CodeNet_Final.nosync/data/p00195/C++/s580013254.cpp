#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int s, t;
    vector<int> v(5);
    while (cin >> s >> t, v[0] = s + t) {
        for (int i = 1; i < 5; i++) cin >> s >> t, v[i] = s + t;
        auto it = max_element(v.begin(), v.end());
        cout << (char)('A' + (it - v.begin())) << " " << *it << endl;
    }
    return 0;
}
