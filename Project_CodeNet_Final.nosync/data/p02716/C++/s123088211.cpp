#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 5;
LL a[N], sum[N], f[N];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        sum[i] = (i > 1 ? sum[i - 2] : 0) + a[i];
    }
    for (int i = 2; i <= n; ++ i){
        if (i & 1) f[i] = max(f[i - 2] + a[i], f[i - 1]);
        else f[i] = max(f[i - 2] + a[i], sum[i - 1]);
    }
    cout << f[n] << endl;
    return 0;
}
