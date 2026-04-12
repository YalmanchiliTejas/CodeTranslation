#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <random>

using namespace std;

#define min(a,b) ((a)<(b) ? (a):(b))
#define max(a,b) ((a)>(b) ? (a):(b))


//INT_MAX
//LONG_LONG_MAX


long long maxd(long long a,long long b){
    if(a>=b){
        return a;
    }
    return b;
}
long long mind(long long a,long long b){
    if(a<=b){
        return a;
    }
    return b;
}

long long gcd(long long a, long long b){
    if(a<b){
        swap(a,b);
    }
    while(b){
        long long r = a%b;
        a=b;
        b=r;
    }
    return a;
}

long long lcm(long long a, long long b){
    return (a*b)/gcd(a,b);
}

int isPrim(int a){
    if(a==1){
        return 0;
    }
    for(int i=2;i<=(a+1)/2;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

long long mod_pow(long long x, long long n, long long mod){
    //xのn乗を計算するのにn乗を2進表記にして計算
    //x^22 = x^16 + x^4 + x^2
    long long ret=1;
    while(n>0){
        if(n%2==1){
            ret=(ret*x)%mod;//答えに付加
        }
        x=(x*x)%mod;//2乗
        n=n/2;
    }
    return ret;
}


struct XX{
    int x;
    int kx;
    int y;
    int ky;
    int i;
    int nearx;
    int neary;
};

class xxIntx {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.x) == (riRight.x)){
            return riLeft.y < riRight.y;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
        }
        //第1条件
        return (riLeft.x) < (riRight.x);
    }
};
class xxInty {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.y) == (riRight.y)){
            return riLeft.x < riRight.x;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
        }
        //第1条件
        return (riLeft.y) < (riRight.y);
    }
};


class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.x) == (riRight.x)){
            return riLeft.i > riRight.i;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
        }
        //第1条件
        return (riLeft.x) > (riRight.x);
    }
};


//union-find
int ppar[200000];
int rrank[200000];

void init(int n){
    for(int i=0;i<n;i++){
        ppar[i]=i;
        rrank[i]=0;
    }
}

int find(int x){
    if(ppar[x]==x){
        return x;
    }else{
        return ppar[x]=find(ppar[x]);
    }
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    if(rrank[x]<rrank[y]){
        ppar[x]=y;
    }else{
        ppar[y]=x;
        if(rrank[x]==rrank[y]){
            rrank[x]++;
        }
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}

//kruskal
struct edge{
    int u;
    int v;
    int cost;
};

bool comp(edge& e1,edge& e2){
    return e1.cost < e2.cost;
}

edge es[200000];

long long kruskal(int V,int E){//V:頂点数,E:辺数
    sort(es,es+E,comp);
    init(V);
    long long res = 0;
    for(int i=0;i<E;i++){
        edge e = es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}



//dijkstra
//struct edge{
//    long to;
//    long cost;
//};
//typedef pair<long,long> P;//first:最短距離、second:頂点番号
//long V;
//vector<edge>G[1001];//G[各頂点番号]
//long d[1001];
//
//int dijkstra(long s){
//    priority_queue<P,vector<P>> que;
//    fill(d,d+V+1,-9223372036854775807);
//    d[s]=0;
//    que.push(P(0,s));
//
//    int index=0;
//    while(!que.empty()){
//        P p=que.top();
//        que.pop();
//        long v=p.second;
//        if(d[v]<p.first){
//            continue;
//        }
//        for(int i=0;i<G[v].size();i++){
//            edge e=G[v][i];
//            if(d[e.to]<d[v]+e.cost){
//                d[e.to]=d[v]+e.cost;
//                que.push(P(d[e.to],e.to));
//            }
//        }
//
//        if(index++>4000000){
//            return -1;
//        }
//    }
//    return 0;
//}


int main(int argc, const char * argv[])
{
    //std::ios::sync_with_stdio(false);
    //scanf("%s",S);
    //scanf("%d",&N);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //cin >> x >> y;
    //テスト用
    //ifstream ifs( "1_06.txt" );
    //ifs >> a;
    //ここから
    
    int N;
    cin >> N;
    XX a[100000];
    //XX a[100];
    for(int i=0;i<N;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        a[i].x=tmp1;
        a[i].y=tmp2;
        a[i].i=i;
    }
    sort(a,a+N,xxIntx());
    
    for(int i=0;i<N-1;i++){
        es[i].u=a[i].i;
        es[i].v=a[i+1].i;
        es[i].cost=a[i+1].x-a[i].x;
    }
    sort(a,a+N,xxInty());
    
    for(int i=0;i<N-1;i++){
        es[i+N-1].u=a[i].i;
        es[i+N-1].v=a[i+1].i;
        es[i+N-1].cost=a[i+1].y-a[i].y;
    }
    long long ans=kruskal(N,2*N-2);
    
    cout << ans << endl;
    
    
    //cout << ans << endl;
    
    //ここまで
    //cout << "ans" << endl;改行含む
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    //printf("%f\n",pow(2,ans.size()));
    
    return 0;
}
