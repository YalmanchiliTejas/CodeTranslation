#include <bits/stdc++.h>
using namespace std;
int a,br;
int main()
{
    for(int i=0;i<3;i++){
        scanf("%d",&a);
        br=br*10+a;
    }
    if(br%4==0){
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}
