#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int h,w,I=0;
  cin>>h>>w;
  char a[h][w];
  pair<int,int> p[h*w];
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
      if(a[i][j]=='.'){
	p[I]=make_pair(i,j);
	I++;
	
      }
    }
  }
  map<int,int> H,W;

  rep(i,I){
    H[p[i].first]++;
   W[p[i].second]++;
  }
  rep(i,h){
    bool flag=false;
    rep(j,w){
      if(H[i]!=w&&W[j]!=h){
	cout<<a[i][j];
	flag=true;
      }
    }
    if(flag)
      cout<<endl;
  }
  //  rep(i,5)
  //cout<<"H=="<<H[i]<<"W=="<<W[i]<<endl;


 
  // rep(i,I)
  //cout<<"("<<p[i].first<<","<<p[i].second<<")"<<endl;


  return 0;
}
