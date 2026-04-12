#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define per(i,n)  for(int i=n-1;i>=0;--i)
#define sc1(a)  scanf("%d",&a)
#define sc2(a,b)  scanf("%d %d",&a,&b)
#define sc3(a,b,c)  scanf("%d %d %d",&a,&b,&c)

int main(){
    int n,m,ans=0,chk=1;
    sc2(n,m);
    int d[8][8];
    vector <int> v(n);
    rep(i,n) v[i]=i;
    rep(i,8) rep(j,8) d[i][j]=0;
    rep(i,m) {
        int a,b;
        sc2(a,b);
        d[a-1][b-1]=1;
        d[b-1][a-1]=1;
    }
    do {
        if (v[0]!=0) continue;
        chk=1;
        rep(i,n-1) chk*=d[v[i+1]][v[i]];
        ans+=chk;
    } while (next_permutation(v.begin(),v.end()));
    printf("%d\n",ans);
    return 0;
}