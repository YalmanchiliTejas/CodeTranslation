#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main() {
    ll n;
    cin >> n;
    
    vector<ull> arr(n);
    for(ll i = 0; i < n; ++i)
        cin >> arr[i];
  
    sort(arr.begin(), arr.end());
    ull k = 0;
    
    while(arr.back() > (n - 1)) {
        ld Z = arr.back() - (n - 1);
        ld N = n;
        ull temp = ceil(Z / N);
        
        k += temp;
        
        for(ll i = 0; i < n - 1; ++i)
            arr[i] += temp;
        arr[n - 1] = arr[n - 1] - (temp * N);
        
        sort(arr.begin(), arr.end());
    }
    
    cout << k << endl;
    
    return 0;
}
