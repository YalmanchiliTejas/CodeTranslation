#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i=0; i<N; i++)
        cin >> arr[i];
    int tallest = 0;
    int counter = 0;
    for (int i=0; i<N; i++) {
        if (arr[i]>=tallest) {
            counter++;
            tallest = arr[i];
        }
    }
    cout << counter << endl;
    return 0;
}

