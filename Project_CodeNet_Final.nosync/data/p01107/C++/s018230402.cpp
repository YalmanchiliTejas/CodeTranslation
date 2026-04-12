#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> P;
int dx[]={0,1,0,-1},dy[]={-1,0,1,0},w,h,x,y,d,c1,c2,c3;
string s[51];
bool b[51][51][4];
main(){
  while(cin>>h>>w,h&&(d=1)){
    vector<P>v;
    memset(b,0,sizeof(b));
    r(i,h)cin>>s[i];
    c1=c2=c3=y=x=0;
    while(1){
      v.push_back(P(y,x));
      if(b[y][x][d])break;
      b[y][x][d]=1;
      if(y==h-1&&(x==w-1||!x)||!y&&x==w-1){
        if(x==w-1&&y==h-1)c1++;
        if(!x&&y==h-1)c2++;
        if(x==w-1&&!y)c3++;
        r(i,v.size()-1)s[v[i].fi][v[i].se]='#';
        v.clear();
      }
      int yy=y+dy[d],xx=x+dx[d];
      if(yy<0||yy>=h||xx<0||xx>=w)d=(d+1)%4;
      else if(s[yy][xx]=='#'&&yy+xx)d=(d+1)%4;
      else{
        int ya=yy+dy[(d+3)%4],xa=xx+dx[(d+3)%4];
        if(ya>=0&&ya<h&&xa>=0&&xa<w&&s[ya][xa]=='.')d=(d+3)%4;
        y=yy,x=xx;
      }
    }
    if(!(y+x)&&c1&&c2&&c3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}