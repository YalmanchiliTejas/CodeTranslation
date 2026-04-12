#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    long long n, ans = 0, mod = 1000000007;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0; 
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
        sum += a.at(i);
        sum %= mod;
    }
    for(int i = 0; i < n; ++i){
        sum -= a.at(i);
        if(sum < 0) sum += mod;
        ans += a.at(i) * sum % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}