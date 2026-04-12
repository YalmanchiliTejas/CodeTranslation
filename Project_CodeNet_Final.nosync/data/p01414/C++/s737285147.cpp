#include<iostream>
#include<queue>
#include<utility>
#include<set>

using namespace std;

int main(){
  int N;
  cin>>N;
  set<int> s;
  for(int i=0;i<N;i++){
    int H,W;
    cin>>H>>W;
    for(int i=0;i<7;i++){
      for(int j=0;j<7;j++){
	bool f[10][10]={};
	for(int k=0;k<H;k++){
	  for(int l=0;l<W;l++){
	    f[i+k][j+l]=true;
	  }
	}
	int b=0;
	for(int k=0;k<4;k++){
	  for(int j=0;j<4;j++){
	    b|=f[k+3][j+3]<<k*4+j;
	  }
	}
	s.insert(b);
      }
    }
  }
  char C[4][5];
  for(int i=0;i<4;i++){
    cin>>C[i];
  }
  int cb[3]={};
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<3;k++){
	cb[k]|=(C[i][j]=="RGB"[k])<<i*4+j;
      }
    }
  }
  queue<pair<int,int> > que;
  bool p[1<<16]={};
  que.push({0,(1<<16)-1});
  for(;;){
    auto cs=que.front();
    if(cs.second==0)break;
    que.pop();
    if(p[cs.second]++)continue;
    for(auto e:s){
      int c=0;
      for(int i=0;i<3;i++){
	c+=(cb[i]&cs.second&e)>0;
      }
      if(c==1){
	que.push({cs.first+1,cs.second&~e});
      }
    }
  }
  cout<<que.front().first<<endl;
}

  