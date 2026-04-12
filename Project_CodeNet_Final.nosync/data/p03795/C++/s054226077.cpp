#include<cstdio>
#include<algorithm>
#define MAXN 1000+10

using namespace std;
int main(){
    int n,x,y;
    scanf("%d",&n);
    x=n*800;
    y=n/15*200;
    printf("%d\n",x-y);
    return 0;
}
