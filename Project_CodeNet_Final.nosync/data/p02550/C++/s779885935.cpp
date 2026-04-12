#include <bits/stdc++.h>
using namespace std;

long long n,x,m;
int chk[100000];

int main() {
    scanf("%lld %lld %lld",&n,&x,&m);
    long long now=x;
    int cycle;
    int cnt=1;
    long long sum=0;
    long long csum=0;
    while (1) {
        if (chk[now]!=0) {
            cycle=cnt-chk[now];
            break;
        }
        chk[now]=cnt++;
        sum+=now;
        now=(now*now)%m;
    }
    int f=cnt-cycle-1;
    cnt=0;
    int save=now;
    while (cnt==0||now!=save) {
        sum-=now;
        csum+=now;
        now=(now*now)%m;
        cnt++;
    }
    long long ret=0;
    if (n<=f) {
        now=x;
        for(int i=0;i<n;i++) {
            ret+=now;
            now=(now*now)%m;
        }
        printf("%lld",ret);
        return 0;
    }
    ret+=sum;
    n-=f;
    ret+=(n/cycle)*csum;
    n%=cycle;
    now=x;
    for(int i=0;i<f;i++) {
        now=(now*now)%m;
    }
    for(int i=0;i<n;i++) {
        ret+=now;
        now=(now*now)%m;
    }
    printf("%lld",ret);
}