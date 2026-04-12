#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

typedef vector <int> vi;

const greater <int> gt;

int main() {
    int n; cin >> n;
    vi A;
    int u;
    
    while(n--) {
        cin >> u;
        auto it = upper_bound(A.begin(), A.end(), u, gt);
        if(it == A.end()) A.push_back(u);
        else *it = u;
    }
    
    cout << A.size();
    
    return 0;
}