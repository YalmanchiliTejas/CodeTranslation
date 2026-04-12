#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)

int main(){
    int n,m=0,ans=0;
    int h[25];
    sc1(n);
    rep(i,n) sc1(h[i]);
    rep(i,n) {
        if (h[i]>=m) {
            m=h[i];
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
