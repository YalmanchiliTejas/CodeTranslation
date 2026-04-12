#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define CVector CPoint
#define INF 0x3f3f3f3f
#define MAXN 1e5
const LL mod=1e9+7;
const double PI=acos(-1.0);
const double EPS=1e-10;

inline int readint(){
  int sum=0;char c=getchar();bool f=0;
  while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
  while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}
  if(f) return -sum;
  return sum;
}

inline LL readLL(){
  LL sum=0;char c=getchar();bool f=0;
  while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
  while(c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}
  if(f) return -sum;
  return sum;
}
struct Edge{
    int s,e,w;
    Edge(int ss,int ee,int ww):s(ss),e(ee),w(ww){}
    Edge(){}
    bool operator <(const Edge & e)const{
        return w<e.w;
    }
};
vector<Edge> edges;
vector<int> parent;
int GetRoot(int a){
    if(parent[a]!=a){
        parent[a]=GetRoot(parent[a]);
    }
    return parent[a];
}

void Merge(int a,int b){
    int p=GetRoot(a);
    int q=GetRoot(b);
    if(p==q){
        return;
    }
    parent[q]=p;
}

struct node{
    int x,y,i;
}s[100005];
bool cmp1(const node &a,const node &b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmp2(const node &a,const node &b){
    if(a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}

int main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y,s[i].i=i;
    sort(s+1,s+n+1,cmp1);
    for(int i=1;i<n;i++){
        edges.push_back(Edge(s[i].i,s[i+1].i,s[i+1].x-s[i].x));
        edges.push_back(Edge(s[i+1].i,s[i].i,s[i+1].x-s[i].x));
    }
    sort(s+1,s+n+1,cmp2);
    for(int i=1;i<n;i++){
        edges.push_back(Edge(s[i].i,s[i+1].i,s[i+1].y-s[i].y));
        edges.push_back(Edge(s[i+1].i,s[i].i,s[i+1].y-s[i].y));
    }
    for(int i=0;i<=n;i++){
        parent.push_back(i);
    }
    sort(edges.begin(),edges.end());
    int nDone=0;
    int totalsum=0;
    for(int i=0;i<edges.size();i++){
        if(GetRoot(edges[i].s)!=GetRoot(edges[i].e)){
            Merge(edges[i].s,edges[i].e);
            nDone++;
            totalsum+=edges[i].w;
        }
        if(nDone==n-1) break;
    }
    cout<<totalsum<<endl;
    return 0;
}

//cout.setf(ios::fixed);
//cout<<fixed<<setprecision(10)<<s<<endl;
