#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#define LL long long
#define PP std::pair<LL,LL>
#define TT std::tuple<LL,LL,LL>
int N;
LL ans;
std::vector<TT> G;
int par[100010];
int rank[100010];
void init(int n){
    for(int i=0;i<n;i++)par[i]=i,rank[i]=0;
}
int find(int x){
    if(par[x]==x)return x;
    else return par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return ;
    if(rank[x]<rank[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rank[x]==rank[y])rank[x]++;
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

std::vector<PP> sx,sy;
int main(){
    std::cin>>N;
    init(N);
    for(int i=0;i<N;i++){
        LL x, y;
        std::cin>>x>>y;
        sx.emplace_back(PP{x,i});
        sy.emplace_back(PP{y,i});
    }
    std::sort(sx.begin(),sx.end());
    std::sort(sy.begin(),sy.end());
    for(int i=0;i<N-1;i++){
        G.push_back(TT{sx[i+1].first-sx[i].first ,sx[i].second ,sx[i+1].second}); 
    }
    for(int i=0;i<N-1;i++){
        G.push_back(TT{sy[i+1].first-sy[i].first ,sy[i].second ,sy[i+1].second});
    }
    std::sort(G.begin(),G.end());
    for(auto u:G){
        int a,b,c;
        std::tie(a,b,c)=u;
        if(!same(b,c)){
            unite(b,c);
            ans+=a;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
