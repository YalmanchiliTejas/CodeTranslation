#include<bits/stdc++.h>
using namespace std;
int h,w,ans;
char a[200];
int main(){
    scanf("%d%d",&h,&w);
    for (int i=1;i<=h;++i) {
        scanf("%s",a);
        for(int j=0;j<=w;++j) {
            if(a[j]=='#') ans++;
        }
    }
    if(ans+1==h+w) printf("Possible");
    else printf("Impossible");
    return 0;
}