#include <iostream>
using namespace std;

int main() {
    int N;
    int H[100];
    int i;

    cin >> N;
    for(i=0; i<N; ++i) {
        cin >> H[i];
    }

    int c = 0;
    int max = 0;
    for(i=0; i<N; ++i) {
        if (H[i] >= max) {
            c++;
            max = H[i];
        }
    }
    cout << c << endl;
    return 0;

} 