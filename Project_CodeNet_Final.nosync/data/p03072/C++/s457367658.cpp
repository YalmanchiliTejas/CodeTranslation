#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n,m,k,ans;
int h[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int tmpMax = -1;
    ans = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",h + i);
        if(tmpMax <= h[i]){
            ans++;
            tmpMax = h[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
