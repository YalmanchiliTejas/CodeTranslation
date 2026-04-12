#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;
        vector<int> score(N);

        for (int i = 0; i < N; i++) {
            cin >> score[i];
        }
        sort(score.begin(), score.end());

        int h = 0;
        for (int i = 1; i < N - 1; i++) {
            h += score[i];
        }
        cout << h / (N - 2) << endl;
    }
}
