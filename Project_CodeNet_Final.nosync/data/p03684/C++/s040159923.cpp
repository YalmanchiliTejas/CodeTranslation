#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL x[100001];
LL y[100001];
typedef pair<LL,LL> P;
vector<P>vx;
vector<P>vy;
vector<P>edge;
vector<P>que;

int par1[200001];
int rank1[200001];
//n要素で初期化
void init(int n){
   for(int i=0;i<n;i++){
       par1[i]=i;
       rank1[i]=0;
   }
}
//木の根を求める
int find(int x){
    if(par1[x] ==x){
         return x;
    }else{
         return par1[x]=find(par1[x]);
    }
}
//xとyの属する集合を併合
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;

    if(rank1[x]<rank1[y]){
         par1[x]=y;
    }else{
         par1[y]=x;
         rank1[x]++;
    }
}
//xとyが同じ集合に属するか否か
bool same(int x,int y){
     return find(x)==find(y);
}

int main(){
    cin>>N;
    REP(i,N){
        LL a,b;
        cin>>a>>b;
        vx.push_back(P(a,i));
        vy.push_back(P(b,i));
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    REP(i,N-1){
        {
           LL a=vx[i].second;
           LL b=vx[i+1].second;
           edge.push_back(P(a,b));
           que.push_back(P(vx[i+1].first-vx[i].first,2*i));
        }
        {
           LL a=vy[i].second;
           LL b=vy[i+1].second;
           edge.push_back(P(a,b));
           que.push_back(P(vy[i+1].first-vy[i].first,2*i+1));
        }
    }
    sort(que.begin(),que.end());
    init(N+10);
    LL ans=0;
    REP(i,que.size()){
        //cout<<"edge"<<
        int num=que[i].second;
        if(same(edge[num].first,edge[num].second)==false){
           unite(edge[num].first,edge[num].second);
           ans+=que[i].first;
        }
    }
    cout<<ans<<endl;
    return(0);
}