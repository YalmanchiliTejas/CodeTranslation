/*
 * @Author: BilyHurington
 * @Date: 2020-03-22 20:53:17
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-22 21:13:36
 */
#include<bits/stdc++.h>
using namespace std;
int n,s,a[3010];
long long f[3010];
const int mod=998244353;
int main(){
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=s-a[i];j>=0;j--){
            f[j+a[i]]=(f[j+a[i]]+f[j])%mod;
        }
        f[a[i]]+=i;
        ans+=f[s]%mod;
        ans%=mod;
        // for(int i=0;i<=s;i++) printf("%lld ",f[i]);
        // printf("\n");
    }
    printf("%lld\n",ans);
    return 0;
}