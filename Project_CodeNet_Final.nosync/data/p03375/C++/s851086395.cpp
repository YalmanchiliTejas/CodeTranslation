#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=3010;
ll n,m,b2[MAX],s[MAX][MAX],c[MAX][MAX],dig[MAX],co[MAX],fin,p2[MAX*MAX];
ll mk_s(ll x,ll y){
    if(x==y) return 1;
    if(y==0) return 1;
    if(s[x][y]==-1){
        s[x][y]=(mk_s(x-1,y-1)+(y+1)*mk_s(x-1,y))%m;
    }
    return s[x][y];
}
ll comb(ll x,ll y){
    if(x==y) return 1;
    if(y==0) return 1;
    if(c[x][y]==-1){
        c[x][y]=(comb(x-1,y-1)+comb(x-1,y))%m;
    }
    return c[x][y];
}
int main(){
    scanf("%lld%lld",&n,&m);
    b2[0]=2,p2[0]=1;
    for(ll i=0;i<=n;i++) for(ll j=0;j<=n;j++) c[i][j]=-1,s[i][j]=-1;
    for(ll i=1;i<=n*n;i++) p2[i]=p2[i-1]*2,p2[i]%=m;
    for(ll i=1;i<=n;i++) b2[i]=b2[i-1]*b2[i-1],b2[i]%=m;
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n-i;j++) dig[i]+=mk_s(n-i,j)*p2[i*j]%m,dig[i]%=m;
        co[i]=comb(n,i);
    }
    for(ll i=0;i<=n;i++){
        if((n-i)%2) fin-=b2[i]*dig[i]%m*co[i]%m,fin+=m;
        else fin+=b2[i]*dig[i]%m*co[i]%m;
        fin%=m;
    }
    printf("%lld\n",fin);
}
