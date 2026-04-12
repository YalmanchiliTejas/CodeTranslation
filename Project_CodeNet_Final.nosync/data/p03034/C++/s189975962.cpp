#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
int s[100005];
map<int, LL> dp1[100005], dp2[100005];
map<int, LL>::iterator its;
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<=n-1;i++) scanf("%d", &s[i]);
    for(int i=1;i<=n-1;i++){
        for(int j=i;j<=n-1;j+=i){
            dp1[j][i] = dp1[j-i][i] + s[j];
        }
    }

    for(int i=1;i<=n-1;i++){
        LL sum = 0;
        int cnt = 1;
        for(int j=(n-1)-i;j>=1;j-=i){
            if(j%i == 0 && cnt >= j/i) sum = -1e18;
            sum += s[j];
            dp2[i][cnt] = sum;
            cnt++;
        }
    }
    LL ans = 0;
    for(int A=1;A<=n-1;A++){
        for(its = dp1[n-1-A].begin();its != dp1[n-1-A].end();its++){
            int d = its->first;
            LL val = its->second;
            if(A <= d) continue;

            int cnt = (n-1-A)/d;
            val += dp2[d][cnt];

            ans = max(ans, val);
        }
    }
    printf("%lld\n", ans);      
}