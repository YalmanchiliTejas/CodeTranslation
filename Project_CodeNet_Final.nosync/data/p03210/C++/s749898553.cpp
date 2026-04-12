#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x;
    cin >> x;
    vector<int> vec{7, 5, 3};
    if (count(vec.begin(), vec.end(), x) > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
