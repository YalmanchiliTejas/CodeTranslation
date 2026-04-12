#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000010;
int n,len,s[MAXN],f[MAXN];
int main () {
    memset(f,0,sizeof(f));
    len=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {scanf("%d",&s[i]);s[i]*=-1;}
    f[1]=s[1];
    for (int i=2;i<=n;i++) {
        int pos=upper_bound(f+1,f+len+1,s[i])-f;
        f[pos]=s[i];
        len=max(len,pos);
    }
    printf("%d",len);
    return 0;
}