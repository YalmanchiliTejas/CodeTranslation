#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second
#define M 1000000007

using namespace std;
typedef long long ll;
ll a[maxn],s[maxn],dp[105][105],n,b[maxn],ans,m;
set <ll> f;

ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M; y>>=1;
    }
    return rt;
}

int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        if (f.find(a[i])==f.end()) f.insert(a[i]),b[++m]=a[i];
    }
    sort(b+1,b+m+1);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (a[i]==b[j]) s[i]=j;
    dp[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=1;j<=s[i];j++){
            if (j<=s[i+1]) (dp[i+1][j]+=dp[i][j]*pow_(2ll,max(b[s[i+1]]-b[s[i]],0ll)))%=M;
            else (dp[i+1][0]+=dp[i][j]*2)%=M;
        }
        (dp[i+1][0]+=dp[i][0]*2)%=M;
        if (s[i+1]>s[i]){
            for (int j=s[i]+1;j<=s[i+1];j++) (dp[i+1][j]+=dp[i][0]*(pow_(2ll,b[j]-b[j-1]-(j==1))-1)*2%M*pow_(2ll,b[s[i+1]]-b[j]))%=M;
        }
    }
    for (int i=0;i<=s[n];i++) (ans+=dp[n][i])%=M;
    cout << (ans+M)%M << endl;
}

