#include <cstdio>
#include <algorithm>
using namespace std;

long long a[200005];

long long pfx[200005][2];
int n;

bool stupid(int x, long long cur, int cnt){
    if (x > n){
        return (cur == 295 && cnt == n/2);
    }
    if (stupid(x+2,cur+a[x],cnt+1)){
        printf("%d\n", x);
        return true;
    }
    return stupid(x+1,cur,cnt);
}
int main(){
    // freopen("test.in", "r", stdin);
    scanf("%d", &n);
    long long c = 0;
    long long b = 0;
    long long tot =0;
    for (int i = 1; i <= n; i++){
        
        scanf("%lld", &a[i]);
        if (i % 2 == 0){
            c+= a[i];
            pfx[i][0] = c;
            pfx[i+1][0] = c;
        }
        else{
            b+= a[i];
            pfx[i][1] = b;
            pfx[i+1][1] = b;
        }
        tot += a[i];
    }
    // stupid(1,0,0);
    long long ans = -1e18;
    if (n % 2 == 0){
        ans = max(pfx[n][0],pfx[n][1]);

        for (int i = 2; i < n; i+=2){
            ans = max(ans, pfx[i][1] + pfx[n][0] - pfx[i][0]);
        }
    }
    else{
        ans = pfx[n][0];
        for (int i = 1; i < n; i++){
            if (i % 2 == 0){
                ans = max(ans, pfx[i-1][1] + max(pfx[n][0] - pfx[i+1][0], pfx[n][1] - pfx[i+1][1]));
            }
            else{
                ans = max(ans, max(pfx[i-1][1],pfx[i-1][0])+ pfx[n][1] - pfx[i+1][1]);
            }
        }
        long long imx = pfx[1][1] - pfx[2][0];
        for (int j = 5; j <= n; j+= 2){

            imx = max(imx, pfx[j-4][1] - pfx[j-3][0]);
            ans = max(ans, imx + pfx[n][1] + pfx[j-1][0] - pfx[j][1]);
            
            // for (int i = 2; i <= j-3; i+=2){
            //         ans = max(ans,pfx[i-1][1] + (pfx[j-1][0] - pfx[i][0]) + pfx[n][1] - pfx[j][1]);
            //         // = pfx[i-1][1] - pfx[i][0] + pfx[j-1][0] - pfx[j][1] + pfx[n][1] 
            // }
        }
    }
    printf("%lld\n", ans);



}