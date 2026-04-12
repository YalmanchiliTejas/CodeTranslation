#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> v;
    long long sum = 0;
    long long MOD = 1e9+7;
    int num;
    long long current, currentsum, ans=0;

    cin >> num;
    for(int i=0;i<num;i++){
        cin >> current;
        v.push_back(current);
        sum += current;
    }
    for(int i=0;i<num;i++){
        sum -= v[i];
        currentsum = sum % MOD;
        ans += v[i] * currentsum;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}