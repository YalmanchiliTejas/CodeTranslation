#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() { 
    int n;
    cin >> n;
    vector<long long int> v(n, 0);
    long long int s = 0;
    long long int res = 0;
    const int mod = 1e9 + 7;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        res += s * v[i];
        res %= mod;
        s += v[i];
        s %= mod;
    }
    cout << res << endl;

}


