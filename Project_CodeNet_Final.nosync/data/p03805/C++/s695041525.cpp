#include<bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;

#define debugv(v) printf("L%d %s => ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;
#define debugm(m) printf("L%d %s is..\n",__LINE__,#m);for(auto v:m){for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) printf("L%d %s is => ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;
#define debugaa(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[x][y]<<" ";}cout<<endl;}
#define debugaar(m,w,h) printf("L%d %s is..\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}
#define ALL(v) (v).begin(),(v).end()
#define BIGINT 0x7FFFFFFF
#define E107 1000000007ll
void printbit(int u){if(u==0)cout<<0;else{int s=0,k=0;for(;0<u;u>>=1,k++)s=(s<<1)|(u&1);for(;0<k--;s>>=1)cout<<(s&1);}}

#define TIME chrono::system_clock::now()
#define MILLISEC(t) (chrono::duration_cast<chrono::milliseconds>(t).count())

namespace{
    std::chrono::system_clock::time_point t;
    void tic(){t=TIME;}
    void toc(){fprintf(stderr,"TIME : %lldms\n",MILLISEC(TIME-t));}
}

template<typename T1,typename T2>
ostream& operator <<(ostream &o,const pair<T1,T2> p){o<<"("<<p.first<<":"<<p.second<<")";return o;}


class UndirectedGraph{
public:
    size_t n;
    vector<vector<int>> vertex_to;
    
    UndirectedGraph(size_t n):n(n),vertex_to(n){}
    
    void connect(int from, int to){
        vertex_to[from].emplace_back(to);
        vertex_to[to].emplace_back(from);
    }
    vector<int>& operator[](int v){
        return vertex_to[v];
    }
    void resize(size_t _n){
        n = _n;
        vertex_to.resize(_n);
    }
    size_t degree(int v){
        return vertex_to[v].size();
    }

};
    
UndirectedGraph g(10);

int width,height;
int m,n;

int dfs(int x,int sum,vector<bool> v){
    if (v[x]) return 0;
    v[x]=true;
    sum|=1<<x;
    
    
    if (sum == (1<<n)-1) return 1;
    
    int r=0;
    for (int to:g.vertex_to[x]){
        r+=dfs(to,sum,v);
    }
    return r;
}

int main(){
    int i,j,k;
    int x,y,a,b;
    
    cin >> n >> m;
    
    for (i=0;i<m;++i){
        scanf("%d%d",&x,&y);
        g.connect(--x,--y);
        
    }
    
    vector<bool> v(n,false);
    cout << dfs(0,0,v) << endl;
    

    return 0;
}