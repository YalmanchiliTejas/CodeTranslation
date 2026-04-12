#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;
using ll = long long;

const int nax = 3005;
ll dp[nax][nax];

int main(){  
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    REP(i,n){
        scanf("%d",&a[i]);
    }
    //dp[0][n-1] 
    for(int L=n-1; L>= 0; L--){
        for(int R=L; R<n; R++){
            dp[L][R] = max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
        }
    }
    printf("%lld\n",dp[0][n-1]);
    return 0;
}
