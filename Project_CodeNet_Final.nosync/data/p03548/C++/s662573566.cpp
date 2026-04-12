#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z,cnt=0;
    scanf("%d%d%d",&x,&y,&z);
    x-=z;
    for(int i=x;i>=y+z;i-=y+z) cnt++;
    printf("%d\n",cnt);
    return 0;
}

