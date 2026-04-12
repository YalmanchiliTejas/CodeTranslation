#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    x-=z;
    int cnt=0;
    for(int i=x;i>=y+z;i-=y+z) cnt++;
    printf("%d\n",cnt);
    return 0;
}

