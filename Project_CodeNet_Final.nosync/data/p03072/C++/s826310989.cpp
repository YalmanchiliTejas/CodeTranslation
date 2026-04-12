#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i=1, p=0, x;i<=n;i++){
        scanf("%d",&x);
        if(x>=p){
            ans++;
            p=x;
        }
    }
    printf("%d\n",ans);
    return 0;
}
