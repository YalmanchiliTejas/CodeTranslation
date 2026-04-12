#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, max=0, c=0;
    cin >> n;
    vector<int> h(n);
    vector<int> v(n, 0);

    for (int i = 0;i < n; ++i) {
        cin >> h[i];
        if (h[i] >= max) {
            max = h[i];
            c++;
        }
    }
    cout << c << endl;
}