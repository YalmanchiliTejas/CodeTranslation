#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, x, m;
    cin >> n >> x >> m;
    vector<int>val(m, 0);
    val[x] = 1;
    long long y = -1, z = -1, len = -1;
    long long sum[100006];
    sum[0] = 0;
    sum[1] = x;
    for(long long i = 2; i <= n; i++){
        x = (x * x) % m;
        if(val[x] != 0){
            y = val[x];
            z = i - 1;
            len = i - y;
            break;
        }
        val[x] = i;
        sum[i] = sum[i - 1] + x;
    }
    if(z == -1){
        cout << sum[n];
    }
    else{
        long long ans = sum[z];
        ans += ((n - z)/len) * (sum[z] - sum[y - 1]);
        long long r = (n - z) % len;
        ans += sum[y + r - 1] - sum[y - 1];
        cout << ans;
    }
    return 0;
}