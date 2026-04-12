#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    int highest = height[0];
    int view = 1;
    for (int i = 1; i < N; i++) {
        if (height[i] >= highest) {
            view += 1;
            highest = height[i];
        }
    }
    cout << view << endl;
    return 0;
}