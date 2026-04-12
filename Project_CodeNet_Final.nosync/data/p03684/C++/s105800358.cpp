#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
int par[100000],n;
typedef std::pair<int,int> pii;
typedef std::pair<int,pii> pipii;
int root(int x){
    if(par[x]==x)return x;
    else return par[x]=root(par[x]);
}
bool unite(int x,int y){
    if(root(x)!=root(y)){
        par[root(x)]=root(y);
        return true;
    }else return false;
}
int main(){
    scanf("%d",&n);
    std::vector<pii> px,py;
    for(int i=0;i<n;i++){
        par[i]=i;
        int x,y;
        scanf("%d%d",&x,&y);
        px.push_back({x,i});
        py.push_back({y,i});
    }
    std::sort(px.begin(),px.end());
    std::sort(py.begin(),py.end());
    std::vector<pipii> g;
    for(int i=1;i<n;i++){
        g.push_back({px[i].first-px[i-1].first,{px[i].second,px[i-1].second}});
        g.push_back({py[i].first-py[i-1].first,{py[i].second,py[i-1].second}});
    }
    std::sort(g.begin(),g.end(),std::greater<pipii>());
    int num=1;
    long long ans=0;
    while(num<n){
        pipii a=g.back();
        g.pop_back();
        if(unite(a.second.first,a.second.second)){
            ans+=(long long)a.first;
            num++;
        }
    }
    printf("%lld",ans);
    return 0;
}