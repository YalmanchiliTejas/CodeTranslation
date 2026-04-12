#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
    int n;
    long long int ans = 0, sum = 0;
    vector<long long int> v, c;

    cin >> n;

    for (int i = 0; i < n; i++){
        v.push_back(0);
        // c.push_back(0);
        cin >> v[i];
        // sum += v[i];
    }

    // c[n-1] = 0;

    for (int i = 0; i < n; i++)
    {
        // c[i] = c[i+1] + v[i+1];
        // // ans = (ans%MOD + (v[i]%MOD * c[i]%MOD)%MOD)%MOD;
        // ans += v[i]*c[i];;
        // ans %= MOD;

        ans += sum*v[i];
        sum += v[i];
        ans %= MOD;
        sum %= MOD;
    }

    cout << ans << endl;

    return 0;
    
}