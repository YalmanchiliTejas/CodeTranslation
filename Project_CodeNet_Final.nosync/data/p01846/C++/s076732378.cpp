#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main(){
  int S,a,b,c,d,j;
  int count;
  int h,w;
  int check=0;
  string e;
  int map[12][12];
  while(1){
  for(int i=0;i<12;i++){
  for(j=0;j<12;j++){
	map[i][j]=2;
      }
    }
    cin>>e;
    if(e[0]=='#') break;
    w=0;
    h=0;
    for(int i=0;i<e.size();i++){
      if('0'<=e[i] && e[i]<='9'){
	S=e[i]-'0';
	for(j=0;j<S;j++){
	  map[h][w]=0;
	  w++;
	}
      }
	if(e[i]=='b'){
	  map[h][w]=1;
	  w++;
	}
	if(e[i]=='/'){
	  w=0;
	  h++;
	}
    }
    /* for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
	cout<<map[i][j];
      }
      cout<<endl;
      }*/
    cin>>a>>b>>c>>d;
    map[a-1][b-1]=0;
    map[c-1][d-1]=1;
    /*    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
	cout<<map[i][j];
      }
      cout<<endl;
      }*/
    rep(i,12){
      count=0;
      for(j=0;j<12;j++){
	if(map[i][j]==0){
	  count++;
	  if(i!=0 && j==0) cout<<"/";
	}
	else if(map[i][j]==2){
	  if(count!=0) cout<<count;
	  count=0;
	  break;
	}
	else{
	  if(i!=0 && j==0) cout<<"/";
	  if(count!=0) cout<<count;
	  cout<<"b";
	  count=0;
	}
      }
      if(j==0) break;
    }
    cout<<endl;
  }
  return 0;
}

