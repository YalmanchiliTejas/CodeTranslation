#include <iostream>
#include <vector>

using namespace std;

int N;
int x[200000];
int y[200000];

int main(){
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        y[i] = x[i];
    }

    sort(x, x + N);

    int m1 = x[N / 2 - 1];
    int m2 = x[N / 2];

    for (int i = 0; i < N; ++i) {
        if (y[i] <= m1) {
            cout << m2 << endl;
        } else {
            cout << m1 << endl;
        }
    }
}