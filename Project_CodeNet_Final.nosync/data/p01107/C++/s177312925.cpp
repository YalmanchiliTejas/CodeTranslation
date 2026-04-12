#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> P;
int dx[]={0,1,0,-1},dy[]={-1,0,1,0},w,h,x,y,d;
string s[51];
bool b[51][51][4];
main(){
  while(cin>>h>>w,h&&(d=1)){
    vector<P>v;
    memset(b,0,sizeof(b));
    int a[3]={};
    r(i,h)cin>>s[i];
    y=0,x=0;
    while(1){
      v.push_back(P(y,x));
      if(b[y][x][d])break;
      b[y][x][d]=1;
      if(y==h-1&&x==w-1){
        a[0]++;
        r(i,v.size()-1)s[v[i].fi][v[i].se]='#';
        v.clear();
      }
      if(y==h-1&&x==0){
        a[1]++;
        r(i,v.size()-1)s[v[i].fi][v[i].se]='#';
        v.clear();
      }
      if(y==0&&x==w-1){
        a[2]++;
        r(i,v.size()-1)s[v[i].fi][v[i].se]='#';
        v.clear();
      }
      int yy=y+dy[d],xx=x+dx[d];
      if(yy<0||yy>=h||xx<0||xx>=w)d=(d+1)%4;
      else if(s[yy][xx]=='#'&&yy+xx)d=(d+1)%4;
      else{
        int ya=yy+dy[(d+3)%4];
        int xa=xx+dx[(d+3)%4];
        if(ya>=0&&ya<h&&xa>=0&&xa<w&&s[ya][xa]=='.')d=(d+3)%4;
        y=yy,x=xx;
      }
    }
    if(!(y+x)&&a[0]&&a[1]&&a[2])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}