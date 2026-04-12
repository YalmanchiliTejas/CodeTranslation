#include <bits/stdc++.h>
using namespace std;

int n,cnt;

long long a[200005],b[200005];

long long ans;

long long cha(long long *s){
    long long minn,maxn;
    minn=maxn=s[1];
    for(int i=1;i<=n;i++){
        maxn=max(maxn,s[i]);
        minn=min(minn,s[i]);
    }
    return maxn-minn;
}
long long mx,mi=1e18,mxx,mix;

struct ha{
    long long a,b;
}u[200005];

bool operator < (const ha &aa,const ha &bb){
    return aa.a<bb.a;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
        if(b[i]<a[i])swap(a[i],b[i]);
        if(mx<b[i]){mxx=i,mx=b[i];}
        if(mi>a[i]){mi=a[i],mix=i;}
    }
    ans=cha(a)*cha(b);

    if(mix==mxx){
        printf("%d\n",ans);
        return 0;
    }

    for(int i=1;i<=n;i++){
         if(i==mix||i==mxx)continue;
         cnt++;
         u[cnt].a=a[i];u[cnt].b=b[i];
    }
    sort(u+1,u+1+cnt);

    long long nmax=max(a[mxx],b[mix]),nmin=min(a[mxx],b[mix]);

    long long d,x;
    d=max(u[cnt].a,nmax);
    x=min(u[1].a,nmin);

    long long maxb,minb;
    maxb=minb=u[1].b;

    ans=min(ans,(d-x)*(mx-mi));
    for(int i=1;i<cnt;i++){
        maxb=max(maxb,u[i].b);
        minb=min(minb,u[i].b);

        d=max(max(u[cnt].a,maxb),nmax);
        x=min(min(minb,u[i+1].a),nmin);

        ans=min((d-x)*(mx-mi),ans);
        //cout<<ans<<endl;
    }


    d=max(maxb,nmax);
    x=min(minb,nmin);

    //cout<<d<<"  -  "<<x<<"  "<<mx-mi<<endl;

    ans=min((d-x)*(mx-mi),ans);

    printf("%lld\n",ans);

    return 0;
}
