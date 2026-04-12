#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    int n;
    vector<int> h(101);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        bool is_view = true;
        for (int j = 0; j < n - 1 && j != i; ++j) {
            if (h[j] > h[i]) { is_view = false; }
        }
        if (is_view) { sum++; }
    }

    cout << sum << endl;
}
