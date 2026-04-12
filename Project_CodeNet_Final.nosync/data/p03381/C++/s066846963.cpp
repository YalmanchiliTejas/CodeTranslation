#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <algorithm>
#include <random>
#include <bitset>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        
        arr[i] = {c, i};
    }
    
    
    sort(arr.begin(), arr.end());
    
    vector<int> ans(n);
    
    int c1 = arr[arr.size() / 2 - 1].first;
    int c2 = arr[arr.size() / 2].first;
    
    for (int i = 0; i < n; ++i) {
        if (i < arr.size() / 2) {
            ans[arr[i].second] = c2;
        } else {
            ans[arr[i].second] = c1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
