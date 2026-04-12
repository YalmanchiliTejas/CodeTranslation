#include<bits/stdc++.h>
#define maxn 10000
using namespace std;
long long mod=998244353;
int n,s;
int a[maxn];
long long wss[maxn];
long long tw[maxn];
long long ps[maxn];
long long rem;
int main() {
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++) {
        for(int i=0;i<=s;i++) tw[i]=wss[i];
        tw[a[i]]+=(i+1);
        for(int j=a[i];j<=s;j++) {
            tw[j]+=wss[j-a[i]];
        }
        rem=rem+((n-i)*(tw[s]-wss[s]))%mod;
        for(int i=0;i<=s;i++) {
            wss[i]=tw[i]%mod;
            tw[i]=wss[i];
        }
    }
    rem+=mod;
    rem%=mod;
    printf("%lld",rem);
    return 0;
}
