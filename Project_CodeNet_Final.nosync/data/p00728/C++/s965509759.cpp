#include <iostream>

using namespace std;


int main(void) {
    int n;
    int score, sum_score;
    int max_score, min_score;
    int i;

    cin >> n;
    while (n) {
        sum_score = 0;
        max_score = 0;
        min_score = 1000;
        for (i=0; i<n; i++) {
            cin >> score;
            sum_score += score;
            if (score < min_score) {
                min_score = score;
            }
            if (score > max_score) {
                max_score = score;
            }
        }

        sum_score -= min_score + max_score;
        cout << sum_score / (n-2) << endl;

        cin >> n;
    }

    return 0;
}