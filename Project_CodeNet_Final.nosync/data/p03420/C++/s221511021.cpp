#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    long long sum = 0;
    for(int b=k+1;b<=n;b++){
        sum += (n+1)/b*max(0,b-k) + max((n+1)%b - k, 0);
    }
    if (k==0)sum -= n;
    printf("%lld",sum);
}
