#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#define maxn 3009
using namespace std;
typedef  long long ll;
#define N 200005
#define fr(i,x,y) for(int i=x;i<=y;i++)
int n,a[N],b[N],cnt[N];
struct node {
    int v, id;

    node() {}

    node(int v, int id) : v(v), id(id) {}

    bool operator<(const node &oth) const {
        return v < oth.v;
    }
}c[N<<1];
void doit(){
    scanf("%d",&n);
    if (n==1){
        puts("0");
        return;
    }
    int ma=-1,tt,ss,mi,maa=-1;
    fr(i,1,n){
        scanf("%d%d",&a[i],&b[i]);
        ma=max(ma,b[i]);
        ma=max(ma,a[i]);

    }
    fr(i,1,n)if (a[i]==ma||b[i]==ma){
            maa=max(maa,a[i]+b[i]-ma);
            if (a[i]+b[i]-ma==maa) tt=i;
        }
    mi=ma+1;
    fr(i,1,n)if (i!=tt){
            mi=min(mi,b[i]);
            mi=min(mi,a[i]);
            if(a[i]==mi) ss=i;
            if(b[i]==mi) ss=i;
        }
    int x,y;
    x=a[ss]+b[ss]-mi;
    y=a[tt]+b[tt]-ma;
    int o=0,gg=0;
    c[o++]=node(x,ss);
    c[o++]=node(y,tt);

    memset(cnt,0,sizeof(cnt));
    fr(i,1,n)if (i!=tt&&i!=ss){
            c[o++]=node(a[i],i);
            c[o++]=node(b[i],i);
        }
    sort(c,c+o);
    int i=0,j=0;
    cnt[c[j].id]++;
    int al=1;
    while (al<n){
        j++;
        if (!cnt[c[j].id]) al++;
        cnt[c[j].id]++;
    }
    gg=1000000008;
    while (1){
        gg=min(gg,c[j].v-c[i].v);
        int idd=c[i].id;
        i++;
        cnt[idd]--;

        if(!cnt[idd]){
            j++;
            while (c[j].id!=idd && j<o)j++;
        }

        if (j>=o) break;
    }


    ll ans2=1LL*(ma-mi)*gg;

    x=a[ss]+b[ss]-mi;
    y=a[tt]+b[tt]-ma;
    if (y<mi) swap(y,mi);
    int t1,t2;
    fr(i,1,n)if (i!=ss&&i!=tt){
            t1=max(a[i],b[i]);
            t2=min(a[i],b[i]);
            if (t2>y) y=t2;
            if (t1<x) x=t1;
        }


    ll ans1=1LL*(ma-x)*(y-mi);

    printf("%lld\n",ans1>ans2?ans2:ans1);
}

int main(){
    //while (1)
    doit();
    return 0;
}