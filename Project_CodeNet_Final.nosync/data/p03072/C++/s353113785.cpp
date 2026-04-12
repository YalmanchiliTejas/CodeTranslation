#include <iostream>

using namespace std;

int main() {
    int N;
    int Hi, maxHi = -1;
    int numInns = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Hi;
        if ( Hi >= maxHi ) {
            numInns += 1;
            maxHi = Hi;
        }
    }
    cout << numInns << endl;
}
