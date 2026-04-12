#include<bits/stdc++.h>
using namespace std;
int h,w;
int main () {
    scanf("%d%d",&h,&w);
    int cnt=0;
    for (int i=1;i<=h;i++) {
        getchar();
        for (int j=1;j<=w;j++) {
            char c=getchar();
            if (c=='#') ++cnt;
        }
    }
    if(cnt==h+w-1) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}