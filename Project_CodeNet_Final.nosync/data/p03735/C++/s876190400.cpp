#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=200005;
struct bag{
    int x,y;
}p[maxn];
bool operator < (bag a,bag b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int n,Rmax,Rmin,Bmax,Bmin;
int main(){
    long long ans=1e18;
    scanf("%d",&n);
    if(n==1){
        cout<<0<<endl;return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        if(p[i].x>p[i].y){
            int k=p[i].x;
            p[i].x=p[i].y;
            p[i].y=k;
        }
    }
    sort(p,p+n);
    int Max=p[0].y,Min=p[0].x,_max=0,_min=0;
    for(int i=1;i<n;i++){
        if(p[i].x<=Min&&p[i].y>=Max){
            Min=p[i].x;Max=p[i].y;
            _max=i;_min=i;
        }
        else if(p[i].x<Min){
            Min=p[i].x;
            _min=i;
        }else if(p[i].y>Max){
            Max=p[i].y;
            _max=i;
        }
    }
    Rmax=Max;Bmin=Min;
    Rmin=p[_min].y;Bmax=p[_max].x;
    for(int i=0;i<n;i++){
        Rmin=min(Rmin,p[i].y);
        Bmax=max(Bmax,p[i].x);
    }
    ans=(long long)(Rmax-Rmin)*(Bmax-Bmin);
    if(_max!=_min){
        Bmax=Max;Bmin=Min;
        Rmax=max(p[n-1].x,p[0].y);
        int premin=p[0].y;
        Rmin=min(p[0].y,p[1].x);
        //sort(p,p+n);
        long long ans0=Rmax-Rmin;
        for(int i=1;i<n-1;i++){
            Rmax=max(p[i].y,Rmax);
            Rmin=min(min(premin,p[i].y),p[i+1].x);
            premin=min(premin,p[i].y);
            if(Rmax-Rmin<ans0)ans0=Rmax-Rmin;
        }
        ans0*=Bmax-Bmin;
        ans=min(ans,ans0);
    }
    cout<<ans<<endl;
    return 0;
}
