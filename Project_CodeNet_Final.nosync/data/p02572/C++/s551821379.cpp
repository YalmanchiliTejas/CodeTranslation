#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    
    int n; cin >> n;
    vector<long long> v(n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i]; 
        sum = (sum + v[i]) % 1000000007;
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        sum -= v[i];
        if(sum < 0) sum += 1000000007;

        ans += (v[i] * sum);
        ans %= 1000000007;
    }

    cout << ans << "\n";

    return 0;
}