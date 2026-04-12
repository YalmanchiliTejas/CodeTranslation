#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];

int main()
{
    int n;
    cin >> n;
    long long ans = 0, sum;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        int l = 0, r = n - 1;
        sum = 0;
        while(r > i && (l < r || r % i))
            ans = max(ans, sum += a[l] + a[r]), l += i, r -= i;
    }
    cout << ans << endl;
    return 0;
}
