#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> x(N), y(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i];
        y[i] = x[i];
    }

    sort(y.begin(), y.end());

    int median = y[N / 2];

    // for (int i = 0; i < N; i++) {

    //     if (i < N / 2) {
    //         cout << x[N / 2 + 1] << endl;
    //     } else {
    //         cout << x[N / 2 - 1] << endl;
    //     }
    // }

    for (int i = 0; i < N; i++) {

        if (x[i] < median) {
            cout << y[N / 2] << endl;
        } else if(x[i] >= median) {
            cout << y[N / 2 - 1] << endl;
        }
    }



}