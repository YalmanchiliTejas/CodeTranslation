#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
typedef long long ll;
using namespace std;

int inf = 1000001;
int mod = 1e9 + 7;
int arr[200007];
int main() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        sum = sum % mod;
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        sum -= arr[i]; 
        if (sum < 0)sum += mod;
        res += sum * arr[i];
        res = res % mod;
    }
    cout << res << endl;
    return 0;
}
