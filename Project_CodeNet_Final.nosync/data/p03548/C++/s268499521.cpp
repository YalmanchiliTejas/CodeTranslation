#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int len = y+z;
    int num = x/len;
    if(x%len < z) printf("%d\n",num-1);
    else printf("%d\n",num);
    return 0;
}
