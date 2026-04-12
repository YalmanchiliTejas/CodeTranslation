#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>

using namespace std;
using llong = long long;
const int MOD=1000000007;


int main(int argc, char**argv){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }

    int ans = 1;
    for (int i = 1; i < n; i++){
        int j;
        for (j = i - 1; j >= 0; j--){
            if (h[i] < h[j]){
               break;
            }
        }
        if (j < 0){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}











