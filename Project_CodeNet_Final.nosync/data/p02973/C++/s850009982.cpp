#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    vector<int> lis;
    deque<int> node;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int a;
        cin >> a;
        node.push_front(a);
    }
    for (auto a: node) {
        auto it = upper_bound(lis.begin(), lis.end(), a);
        if (it == lis.end()) {
            lis.push_back(a);
        } else {
            *it = a;
        }
    }
    cout << lis.size() << endl;
    return 0;
}
