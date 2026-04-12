#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set> 
#include <bitset>
#include <cmath>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)

int main () {
    
    int n; cin >> n;
    vector<int> h(n);
    REP(i,n) {
        cin >> h[i];
    }

    int res = 0;
    for (int i = n-1; i >= 0; i--) {
        int mx = -1;
        for (int j = 0; j < i; j++) {
            mx = max(mx, h[j]);
        }
        if(mx <= h[i]) {
            res += 1;
        } 
    }
    
    cout << res << endl;
    return 0;
}

