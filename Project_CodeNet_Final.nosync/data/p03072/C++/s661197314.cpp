#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <string>
#include <tuple>

typedef long long ll;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int& hc : h) cin >> hc;
    int mx = -1;
    int ret = 0;
    for(int i=0; i<n ; ++i){
        mx = max(h[i], mx);
        if (mx <= h[i]){
            ++ret;
        }
    }
    cout << ret << endl;
}
