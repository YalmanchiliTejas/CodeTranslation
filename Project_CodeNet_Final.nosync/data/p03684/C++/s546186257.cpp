#include <iostream>
#include <algorithm>
using namespace std;
 
 
const int N=200000+10;
int Father[N];
 
int find(int x){
    return Father[x]==x ? x:Father[x]=find(Father[x]);
}
 
void Union(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        Father[fx]=fy;
    }    
}
 
struct TnT{
    int x;
    int y;
    int id;
}T[N];
 
struct side{
    int u;
    int v;
    int d;
}S[N];
 
bool cmpx(TnT a,TnT b){
    return a.x<b.x;    
}
 
bool cmpy(TnT a,TnT b){
    return a.y<b.y;    
}
 
bool cmpd(side a,side b){
    return a.d<b.d;    
}
 
int main(){
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>T[i].x>>T[i].y;
        T[i].id=i;
        Father[i]=i;
    }
    
    sort(T+1,T+1+n,cmpx);
    for(int i=1;i<n;i++){
        S[m].u=T[i].id;
        S[m].v=T[i+1].id;
        S[m].d=T[i+1].x-T[i].x;
        m++;
    }
    
    sort(T+1,T+1+n,cmpy);
    for(int i=1;i<n;i++){
        S[m].u=T[i].id;
        S[m].v=T[i+1].id;
        S[m].d=T[i+1].y-T[i].y;
        m++;
    }
    
    long long ans=0;
    sort(S,S+m,cmpd);
    for(int i=0;i<m;i++){
        if(find(S[i].u)!=find(S[i].v)){
            ans+=S[i].d;
            Union(S[i].u,S[i].v);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}