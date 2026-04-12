#include <bits/stdc++.h>
using namespace std;

using LL = long long int;

class Solution {
public:
    vector<int> solve(int n, vector<int> &a) {
        vector<int> b(n);
        for(int i = 0, left = 0, right = n-1; left <= right; ++ left, -- right, ++ i) {
            b[left] = a[n - 1 - i * 2];
            if(left == right) {
                break;
            }
            b[right] = a[n - 2 - i * 2];
        }
        return b;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &ai : a) {
        cin >> ai;
    }
    for(auto bi : s.solve(n, a)) {
        cout << bi << ' ';
    }
    cout << endl;
//    auto b = s.solve(n, a);
//    for(int i = 0; i < n; ++ i) {
//        if(i) {
//            cout << ' ';
//        }
//        cout << b[i];
//    }
//    cout << endl;
    return 0;
}
