#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
typedef pair<int,int>P;
typedef pair<P,vector<P> >P2;
bool used[51][51];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
string s[51];
int a[51][51][3],x,y;
int cx,cy,c,h,w,Q,ans;
int main(){
  vector<int>V[3000];
  cin>>h>>w>>Q;
  r(i,h)cin>>s[i];
  r(k,3)r(i,h)r(j,w)cin>>a[i][j][k];
  cin>>cy>>cx;
  V[cy*51+cx].push_back(0);
  r(i,Q-1){
    cin>>y>>x;
    queue<P2>q;
    vector<P>v,ans;
    v.push_back(P(cx,cy));
    memset(used,0,sizeof(used));
    used[cy][cx]=1;
    q.push(P2(P(cx,cy),v));
    while(!q.empty()){
      P2 pt=q.front();q.pop();
      int ax=pt.first.first;
      int ay=pt.first.second;
      if(ax==x&&ay==y)ans=pt.second;
      r(j,4){
        int yy=ay+dy[j];
        int xx=ax+dx[j];
        if(yy<0||xx<0||yy>=h||xx>=w)continue;
        if(s[yy][xx]=='#')continue;
        if(used[yy][xx])continue;
        vector<P>v2=pt.second;
        v2.push_back(P(xx,yy));
        used[yy][xx]=1;
        q.push(P2(P(xx,yy),v2));
      }
    }
    cx=x;
    cy=y;
    r(j,ans.size()-1){
      V[ans[j+1].second*51+ans[j+1].first].push_back(++c);
    }
  }
  r(i,51)r(j,51){
    r(k,(int)V[i*51+j].size()-1){
      int x1=V[i*51+j][k];
      int x2=V[i*51+j][k+1];
      ans+=min(a[i][j][1]+a[i][j][2],(x2-x1)*a[i][j][0]);
    }
    if(V[i*51+j].size())ans+=a[i][j][1]+a[i][j][2];
  }
  cout<<ans<<endl;
}