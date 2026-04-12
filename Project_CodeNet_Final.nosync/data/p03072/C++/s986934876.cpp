#include <bits/stdc++.h>
using namespace std;
int ax[500];
int main(){
    int N;
    scanf("%d",&N);
    for(int i = 1;i<=N;i++)scanf("%d",&ax[i]);
    int ans = 1;
    for(int i = 2;i<=N;i++){
        bool flag = 1;
        for(int j = 1;j<=i-1;j++)if(ax[j]>ax[i])flag = 0;
        ans+=flag;
    }
    printf("%d\n",ans);
    return 0;
}
