#include <iostream>
using namespace std;

int main() {
    int count;
    while (cin >> count && count > 0) {
        int cur;
        int sum = 0;
        int maxScore = 0;
        int minScore = 1001;
        for (int i = 0; i < count; i++) {
            cin >> cur;
            sum += cur;
            maxScore = max(maxScore, cur);
            minScore = min(minScore, cur);
        }
        cout << (sum - minScore - maxScore) / (count - 2) << endl;
    }
    return 0;
}
