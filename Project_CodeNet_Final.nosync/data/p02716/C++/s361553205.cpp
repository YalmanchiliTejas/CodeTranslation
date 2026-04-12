// Created by CAD on 2020/4/19.
#include <bits/stdc++.h>

#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x7fffffffffffffff
#define mst(name, value) memset(name,value,sizeof(name))
#define FOPEN freopen("C:\\Users\\14016\\Desktop\\cad.txt","r",stdin)
#define tst1(a) cout<<#a<<":"<<a<<endl
#define tst2(a, b) cout<<#a<<":"<<a<<" "<<#b<<":"<<b<<endl
#define tst3(a, b, c) cout<<#a<<":"<<a<<" "<<#b<<":"<<b<<" "<<#c<<":"<<c<<endl
#define tst4(a, b, c, d) cout<<#a<<":"<<a<<" "<<#b<<":"<<b<<" "<<#c<<":"<<c<<" "<<#d<<":"<<d<<endl
#define lson (p<<1)
#define rson (p<<1|1)
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define ll long long
#define lowbit(i) (i&-i)
using namespace std;

const int maxn=2e5+5;
ll a[maxn];
ll dp[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    dp[1]=a[1],dp[2]=a[2];
    for(int i=3;i<=n-(n&1);++i){
        if(i&1) dp[i]=a[i]+dp[i-2];
        else dp[i]=a[i]+max(dp[i-2],dp[i-3]);
    }
    if(n&1){
        ll bj=a[n],ans=max(dp[n-1],dp[n-2]);
        for(int i=n-2;i>=3;i-=2){
            ans=max(ans,bj+max(dp[i-1],dp[i-2]));
            bj+=a[i];
        }
        cout<<max(ans,bj)<<"\n";
    }
    else cout<<max(dp[n-1],dp[n]);
    return 0;
}
