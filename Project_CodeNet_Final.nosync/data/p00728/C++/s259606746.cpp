#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    while(cin >> n, n) {
        vector<int> v(n);
        for(int i=0; i<n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << accumulate(v.begin()+1, v.end()-1, 0) / (v.size()-2) << endl;
    }
}