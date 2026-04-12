#include "cstdio"
#include "algorithm"
using namespace std;
long long dp[100010];
int main(){
    int n=0;
    for(int i=1;i<=3;i++){
        int a; scanf("%d",&a);
        n=n*10+a;
    }
    if(n%4) puts("NO");
    else puts("YES");
    return 0;
}
