#include <iostream> 
#include <string>
#include <vector>

using namespace std;
int main() {
    int n, maxValue = 0, count = 0;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[n];
        if (h[n] >= maxValue) {
            maxValue = h[n];
            count++;
        }
    }

    cout << count << endl;

    return 0;
}