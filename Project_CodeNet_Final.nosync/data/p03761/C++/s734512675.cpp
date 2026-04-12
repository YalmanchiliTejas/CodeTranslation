#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 'a'; i <= 'z'; i++) {
        int cnt = 50;
        for (int j = 0; j < N; j++) {
            int res = 0;
            for (int k = 0; k < S[j].size(); k++) {
                if (S[j][k] == i) {
                    res++;
                }
            }
            cnt = min(cnt, res);
        }
        std::cout << string(cnt, i);
    }

    std::cout << endl;
}