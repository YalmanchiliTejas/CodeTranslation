#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool is_viewable(vector<int> &H, int i);

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (is_viewable(H, i)) {ans += 1;}
    }
    cout << ans << endl;
    return 0;
}

bool is_viewable(vector<int> &H, int i) {
    for (int j = 0; j < i; ++j ) {
        if (H[j] > H[i]) {return false;}
    }
    return true;
}
