#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
using namespace std;

constexpr int64_t MOD=1e9+7;
int64_t inv[200010];
int64_t x,y;
void gcd(int64_t a, int64_t b){
    if(a==0){
        x=0,y=1;
    } else if(a==b || b==0){
        x=1,y=0;
    } else if(a<b){
        gcd(a,b%a);
        x-=(b/a)*y;
    }else{
        gcd(a%b,b);
        y-=(a/b)*x;
    }
}

void init_inv(){
    for(int i=1;i<=200000;++i){
        gcd(i,MOD);
        inv[i]=x;
    }
}

int64_t comb(int n, int k){
    int64_t ans=1;
    for(int i=n,j=1;i>=0&&j<=k;++j,--i){
        ans*=(i*inv[j])%MOD;
        ans%=MOD;
    }
    return ans;
}

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    init_inv();
    int64_t c=comb(n*m-2,k-2);
    int64_t cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int64_t x[]={j-1,m-j,i-1,n-i};
            int64_t y[]={n,n,m,m};
            for(int k=0;k<4;++k){
                int64_t d=(x[k]*(x[k]+1))/2;
                d%=MOD;
                cnt+=(d*y[k])%MOD;
                cnt%=MOD;
            }
        }
    }
    cnt*=inv[2];
    cnt%=MOD;
    int64_t ans=(c*cnt)%MOD;
    if(ans<0)ans+=MOD;
    cout<<ans<<endl;
    return 0;
}
