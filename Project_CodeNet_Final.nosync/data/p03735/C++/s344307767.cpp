#include<cstdio>
#include<algorithm>
struct Element{
    int id;
    long long value;
    Element(){}
    Element(int id,long long value):id(id),value(value){}
};
long long x[200005][2];
Element b[400005];
int vis[200005];

long long min(long long a,long long b){ return a>b?b:a; }

long long max(long long a,long long b){ return a>b?a:b; }

int main(){
    int n;
    scanf("%d",&n);
    long long minn = 1e13+7, maxn = -1;
    long long minn1 = 1e13+7, maxn0 = -1;
    int size = 0;
    for(int i = 1; i <= n; i++){ 
        scanf("%lld%lld",&x[i][0],&x[i][1]);
        if(x[i][0]>x[i][1]){
            long long cur = x[i][0];
            x[i][0] = x[i][1];
            x[i][1] = cur;
        }
        b[++size] = Element(i,x[i][0]);
        b[++size] = Element(i,x[i][1]);
        if(minn>x[i][0]) minn = x[i][0];
        if(maxn<x[i][1]) maxn = x[i][1];
        if(minn1>x[i][1]) minn1 = x[i][1];
        if(maxn0<x[i][0]) maxn0 = x[i][0];
    }
    long long ans = (maxn0-minn)*(maxn-minn1);
    //printf("ans = %lld\n",ans);
    //below is wrong
    std::sort(b+1,b+1+size,[&](Element& u,Element& v){
        return u.value<v.value;
    });
    long long curMaxn = maxn0;
    int p = 1;
    while(p<=size){
        long long offer = (curMaxn-b[p].value)*(maxn-minn);
        if(ans>offer) ans = offer;
        int np = p;
        while(np+1<=size && b[np+1].value==b[p].value) np++;
        int ok = 1;
        for(int i = p; i <= np ;i++){
            if(vis[b[i].id]) ok = 0;
            else{ 
                vis[b[i].id] = 1;
                curMaxn = max(curMaxn,x[b[i].id][1]);
            }
        }
        if(!ok) break;
        else p = np+1;
    }
    printf("%lld\n",ans);
    return 0;
}
