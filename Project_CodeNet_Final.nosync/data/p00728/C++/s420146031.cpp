#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define repeat(i, n) for(int i=0; i < (n); i++) 

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> scores;
        repeat(i, n) {
            int s; cin >> s;
            scores.push_back(s);
        }
        int max_s, min_s;
        max_s = *max_element(scores.begin(), scores.end());
        min_s = *min_element(scores.begin(), scores.end());
        int sum = -max_s-min_s;
        repeat(i, n) {
            sum += scores[i];
        }
        int average = sum / (n-2);
        cout << average << endl;
    }
    return 0;
}

        