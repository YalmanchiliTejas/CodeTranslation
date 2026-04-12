#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(cin >> n, n) {
        vector<int> v(n);
        int sum = 0;
        for(int i=0; i<n; ++i) {
            cin >> v[i];
            sum += v[i];
        }
        sort(begin(v), end(v));
        cout << (sum - v[0] - v[v.size()-1])/(v.size()-2) << endl;
    }
}
