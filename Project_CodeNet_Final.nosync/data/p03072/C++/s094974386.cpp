#include <iostream> 
using namespace std;
int main() {
    int n, maxValue = 0, count = 0, h;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h >= maxValue) {
            maxValue = h;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}