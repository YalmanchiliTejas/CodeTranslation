#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum, ans;
    sum = 0;
    ans = 0;
    for (int i = 0; i < a.size(); i++){
        cin >> a[i];
        sum += a[i];
        sum %=mod;
    }
    
    for(int i = 0; i < n; i ++){
        sum -= a[i];
        if(sum < 0){
            sum += mod;
        }
        ans += a[i] * sum;
        ans %=mod;
    }
    cout << ans << endl;

    return 0;
}