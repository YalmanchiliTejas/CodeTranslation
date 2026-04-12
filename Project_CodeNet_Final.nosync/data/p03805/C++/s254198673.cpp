#include <bits/stdc++.h>

using namespace std;
int a[55][55];
char b[] = "123456789";
int main(){
    int i,n,m,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        {
        scanf("%d%d",&x,&y);
        a[x][y] = a[y][x] = 1;
    }
    b[n] = 0;
    int ans =0;
    while(1)
        {
        int valid = 1;
        for(i=1;i<n;i++)
            {
            x = b[i-1]-'0';
            y = b[i]-'0';
            if(a[x][y]==0)
                {
                valid = 0; break;
            }
        }
        ans += valid;
        
        if(!next_permutation(b+1,b+n))break;
    }
    printf("%d\n",ans);
    return 0;
}
