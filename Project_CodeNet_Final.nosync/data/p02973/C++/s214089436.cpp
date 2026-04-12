#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;

int main(int argc, const char * argv[]) {
    
   ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    vector<int> v(1);
    cin >> v[0];
    for (int i = 1; i < n; i++) {
        int a; cin >> a;;
        if (v[v.size() - 1] >= a) {
            v.push_back(a);
        } else {
            *upper_bound(v.begin(), v.end(), a, greater<int>()) = a;
        }
    }
    
    cout << v.size() << endl;
    
    return 0;
}
