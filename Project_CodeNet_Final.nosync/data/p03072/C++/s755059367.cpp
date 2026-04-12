#include <iostream>
#include <vector>

using namespace std;

int f(vector<int> h) {
    int result = 1;
    int min = h[0];

    for (int i = 1; i < h.size(); i++) {
        if (min <= h[i]) {
            min = h[i];
            result++;
        }
    }

    return result;
}

int main() {

    int n;
    cin >> n;

    vector<int> h;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        h.push_back(tmp);
    }

    int result = f(h);
    cout << result << endl;

    return 0;
}
