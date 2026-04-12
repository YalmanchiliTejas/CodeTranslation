#include <bits/stdc++.h>
using namespace std;

int main() {

    //input
    int N; cin >> N;
    vector<int>H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H.at(i);
    }
    int count = 1;
    for (int i = 1; i < N; ++i) {
        bool canView = true;
        for (int j = i - 1; j >= 0 ; --j) {
            if(H.at(i) < H.at(j)){
              canView = false;
            }
        }
        if(canView == true) count++;
    }
    cout << count;

    return 0;
}