#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
const int N=2e5;

int main(){
int n;
cin>>n;
int a[n];
rep(i,n) scanf("%d",&a[i]);
if(n%2==0){
ll dp[n];
dp[0]=a[0];
dp[1]=a[1];
    for(int i=2;i<n;i++){
    if(i%2==0)
        dp[i]=dp[i-2]+a[i];
    else
        dp[i]=max(dp[i-3],dp[i-2])+a[i];
    }
    printf("%lld\n",max(dp[n-1],dp[n-2]));
}
else{
    vector<ll>l(n/2),m(n/2),r(n/2);
    l[0]=a[0];
    m[0]=a[1];
    r[0]=a[2];
    for(int i=1;i<n/2;i++){
        l[i]=l[i-1]+a[2*i];
        m[i]=max(l[i-1],m[i-1])+a[2*i+1];
        r[i]=max(l[i-1],max(m[i-1],r[i-1]))+a[2*i+2];
    }
    printf("%lld\n",max(l[n/2-1],max(m[n/2-1],r[n/2-1])));
}

return 0;
}
