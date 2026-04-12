#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 1;
    int min;
    cin >> min;

    for (int i = 0; i < N - 1; i++) {
        int H;
        cin >> H;
        if (H >= min) {
            count++;
            min = H;
        }
    }

    cout << count << endl;
}