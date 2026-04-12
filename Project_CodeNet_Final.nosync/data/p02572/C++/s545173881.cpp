#include <algorithm>
#include <iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int a[200005];
ll suf[200005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--){
        suf[i] = suf[i + 1] + a[i];
        
    }
        

    ll res=0;

    for (int i = 0; i < n;i++){
        res += (suf[i + 1]%mod * a[i]%mod) % mod;
        res %= mod;

    }
    cout << res;
    return 0;
}