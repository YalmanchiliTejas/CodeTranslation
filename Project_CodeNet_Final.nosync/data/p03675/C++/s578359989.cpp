#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
const ll INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> b = {};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (n % 2 == 0) {
            if(i % 2 == 0) b.push_back(a);
            else b.insert(b.begin(), a);
        } else {
            if (i % 2 == 1) b.push_back(a);
            else b.insert(b.begin(), a);
        }
    }

    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;

    return 0;
}