#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
long long arr[N];
const int mod = (int)1e9 + 7;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> arr[i];
    long long s = 0,ans = 0;
    for(int i = 1;i <= n;i++){
        ans += (arr[i] * s);
        s += arr[i];
        ans %= mod;
        s %= mod;
    }
    cout << ans;
    return 0;
}