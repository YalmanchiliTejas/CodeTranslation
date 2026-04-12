#include <stdio.h>
int main() {
    int cnt,u,d,l,r,f,b,N,g;char T[20];while (scanf("%d",&N)!=EOF && N) {
        cnt=1,u=1,f=2,r=3,d=6,l=4,b=5;while (N--) {
            scanf("%s",&T);
            if (T[0]=='N') g=u,u=f,f=d,d=b,b=g;
            else if (T[0]=='E') g=u,u=l,l=d,d=r,r=g;
            else if (T[0]=='S') g=u,u=b,b=d,d=f,f=g;
            else if (T[0]=='W') g=u,u=r,r=d,d=l,l=g;
            else if (T[0]=='L') g=f,f=l,l=b,b=r,r=g;
            else g=f,f=r,r=b,b=l,l=g;
            cnt+=u;
        }
        printf("%d\n",cnt);
    }
    return 0;
}