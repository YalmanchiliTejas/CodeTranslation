#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int mod=1000000007;
    char s[51];
    int n;
    for (;;) {
        scanf("%d",&n);
        if (n==0) break;

        int ans[n][n];
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                ans[i][j]=-1;
            }
        }

        int x=n/2, y=n/2+1;
        for (int i=1;i<=n*n;++i) {
            ans[y][x]=i;
            y=(y+1)%n;
            x=(x+1)%n;
            if (ans[y][x]!=-1) {
                y=(y+1)%n;
                x=(x+n-1)%n;
            }
        }
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j) {
                if (j<n-1) {
                    printf("%4d",ans[i][j]);
                } else {
                    printf("%4d\n",ans[i][j]);
                }
            }
        }
    }
    return 0;
}