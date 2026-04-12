#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long int n, arr[N], cs[N];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    long long int ans = 0, mod = 1e9 + 7, sum = arr[0];
    for(int i = 1 ; i < n; i++){
        ans += sum * arr[i] % mod;
        ans %= mod;
        sum += arr[i];
        sum %= mod;
    }
    cout << ans << endl;
    return 0;
}