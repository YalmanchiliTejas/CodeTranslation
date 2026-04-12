#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
#define LL long long
int n;
LL a[N], f[N][2];
int main(){
    cin>>n;
    for(int i = 1;i <= n; i++){
        scanf("%lld", &a[i]);
    }
    memset(f, -127, sizeof f);
    f[0][0] = 0;
    for(int i = 0;i < n / 2; i++){
        for(int j = 0;j <= 1; j++){
            LL F = f[i][j];
            f[i+1][1] = max(f[i+1][1], F + a[i*2+2]);
            if(j != 1)f[i+1][0] = max(f[i+1][0], F + a[i*2+1]);
        }
    }
    if(n & 1){
        LL sum = a[n];
        LL ans = max(f[n/2][1], f[n/2][0]);
        int num = 1;
        for(int i = n - 2;i > 1; i -= 2){
            ans = max(ans, sum + max(f[(i-1)/2][0], f[(i-1)/2][1]));
            num++;
            sum += a[i];
            if(num == n / 2)ans = max(ans, sum);
        }
        cout<<ans<<endl;

    }
    else {
        printf("%lld\n", max(f[n/2][0], f[n/2][1]));
    }
    return 0;
}
