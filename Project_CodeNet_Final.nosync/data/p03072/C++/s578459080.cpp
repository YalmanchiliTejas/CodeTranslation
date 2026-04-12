#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);

    for (int i = 0; i < h.size(); ++i) cin >> h[i];

    int count = 0;
    int max = 0;
    for (int i = 0; i < h.size(); ++i) {
        if (h[i] >= max) {
            max = h[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}