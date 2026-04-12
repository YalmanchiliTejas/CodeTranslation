#include <iostream>

using namespace std;

int main() {
    int n;
    int h;

    cin >> n;
    cin >> h;

    int counter = 1;
    int max = h;

    for (int i = 1; i < n; i++) {
        cin >> h;
        if (max <= h) {
            max = h;
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}

