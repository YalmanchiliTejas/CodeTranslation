#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ret = 0;
    int top = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (top <= tmp) {
            top = tmp;
            ret++;
        }
    }
    cout << ret << endl;
}
