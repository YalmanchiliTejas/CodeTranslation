#include<cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int y = n/15*200;
    int ans = 800*n-y;
    printf("%d\n",ans);

    return 0;
}