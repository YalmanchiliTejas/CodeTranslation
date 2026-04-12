#include <bits/stdc++.h>
#define INF (1e9)
using namespace std;
struct data{int y,x;};
int n;
data stmp[16];
bool can[16][16];
string mp[16];
char RGB[3]={'R','G','B'};

void Min(int &a,int b){a=min(a,b);}
int Idx(int y,int x){return y*4+x;}

int getBit(int sta,data a,data b,char ch){
  int res=0;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      if(a.x<=j&&j<=b.x&&a.y<=i&&i<=b.y)res|=(mp[i][j]==ch)<<Idx(i,j);
      else res|=(sta&(1<<Idx(i,j)));
    }
  return res;
}


typedef pair<int,int> P;
int DP(){
  vector<int>D(1<<16,INF);
  queue<int> Q;
  Q.push(0);
  D[0]=0;
  while(!Q.empty()){
    int bit=Q.front();Q.pop();
    if(bit==(1<<16)-1)break;
    for(int i=0;i<3;i++)
      for(int a=0;a<16;a++)
	for(int b=0;b<16;b++)
	  if(can[a][b]){
	    data yx=(data){a/4,a%4};
	    data YX=(data){b/4,b%4};
	    int nbit=getBit(bit,yx,YX,RGB[i]);
	    if(D[nbit]==INF)Q.push(nbit),D[nbit]=D[bit]+1;
	  }

  }
  return D[(1<<16)-1];
}

void mk_can(){
  for(int i=0;i<n;i++){
    int w=stmp[i].x,h=stmp[i].y;
    for(int y=-3;y<4;y++)
      for(int x=-3;x<4;x++){
	int a=max(0,y),b=max(0,x);
	int Y=min(3,y+h-1);
	int X=min(3,x+w-1);
	if(a>Y||b>X)continue;
	can[Idx(a,b)][Idx(Y,X)]=1;
      }
  }
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>stmp[i].y>>stmp[i].x;
  for(int i=0;i<4;i++)cin>>mp[i];
  mk_can();
  cout<<DP()<<endl;
  return 0;
}