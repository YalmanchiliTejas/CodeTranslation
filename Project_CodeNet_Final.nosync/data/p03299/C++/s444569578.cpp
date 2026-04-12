#include<bits/stdc++.h>
#define fi first
#define se second
#define Mp make_pair
#define pb push_back
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int N = 103,mod = 1e9+7,inf=0x3f3f3f3f;
int n,a[N];

int qpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1) ret=(ll)ret*a%mod;
        a=(ll)a*a%mod; b>>=1;
    }
    return ret;
}
PII solve(int l,int r,int h){
    if(l==r) {
        int x=qpow(2,a[l]-h);
        //printf("%d %d %d %d\n",l,a[l],h,x);
        return Mp(x,x);
    }
    int mnh=inf;
    rep(i,l,r) mnh=min(mnh,a[i]);
    int c=1,t=qpow(2,mnh-h);
    rep(i,l,r) if(a[i]==mnh) c=(ll)c*2%mod;
    int x=1,y=1;
    for(int i = l,j=l; i<=r; i=j+1,j=i){
        if(a[i]==mnh) continue;
        while(j<r&&a[j+1]!=mnh) j++;
        PII ret=solve(i,j,mnh);
        x=(ll)x*ret.fi%mod;
        y=(ll)y*(ret.fi+ret.se)%mod;
    }
    int f=(ll)x*t%mod;
    int s=((ll)c*y+(ll)(t-2+mod)*x)%mod;
    //printf("%d %d %d %d\n",x,y,f,s);
    return Mp(f,s);
}

int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    printf("%d\n",solve(1,n,0).se);
    return 0;
}