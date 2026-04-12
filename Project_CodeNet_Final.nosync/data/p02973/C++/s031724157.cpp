#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> x(n + 1, -INF);
    for(int i = 0; i < n; i++) {
        int index = lower_bound(x.begin(), x.end(), v[i]) - x.begin() - 1;
        x[index] = v[i];
    }
    
    for(int i = n; i >= 0; i--) {
        if(x[i] == -INF) {
            cout << n - i << endl;
            return 0;
        }
    }
}
