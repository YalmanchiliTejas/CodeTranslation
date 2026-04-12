#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int countInn = 1;
    int highestInn;
    cin >> highestInn;
    for(int i = 1; i < N; i++) {
        int nextInnH;
        cin >> nextInnH;
        if(nextInnH >= highestInn) {
            highestInn = nextInnH;
            countInn++;
        }
    }
    cout << countInn;

    return 0;
}