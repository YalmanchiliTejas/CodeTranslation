#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int a[8][3]={
    {0,0,0},
    {0,1,1},
    {1,0,1},
    {1,1,0},
    {0,0,1},
    {0,1,0},
    {1,0,0},
    {1,1,1}
  };
  int N;
  string s;
  cin >> N >> s;
  string t;
  for(int i=0; i<4; i++){
    int cnt=0;
    int l;
    vector<int> u(N);
    if(s.at(0)=='o') l=i;
    if(s.at(0)=='x') l=i+4;
    u.at(0)=a[l][1];
    u.at(1)=a[l][2];
    for(int j=1; j<N-1; j++){
      if(s.at(j)=='o'){
        if(u.at(j-1)==0 && u.at(j)==0) u.at(j+1)=0;
        if(u.at(j-1)==0 && u.at(j)==1) u.at(j+1)=1;
        if(u.at(j-1)==1 && u.at(j)==0) u.at(j+1)=1;
        if(u.at(j-1)==1 && u.at(j)==1) u.at(j+1)=0;
      }
      if(s.at(j)=='x'){
        if(u.at(j-1)==0 && u.at(j)==0) u.at(j+1)=1;
        if(u.at(j-1)==0 && u.at(j)==1) u.at(j+1)=0;
        if(u.at(j-1)==1 && u.at(j)==0) u.at(j+1)=0;
        if(u.at(j-1)==1 && u.at(j)==1) u.at(j+1)=1;
      }
    }
    if(s.at(N-1)=='o'){
        if(u.at(N-2)==0 && u.at(N-1)==0 && u.at(0)==1) cnt=-1;
        if(u.at(N-2)==0 && u.at(N-1)==1 && u.at(0)==0) cnt=-1;
        if(u.at(N-2)==1 && u.at(N-1)==0 && u.at(0)==0) cnt=-1;
        if(u.at(N-2)==1 && u.at(N-1)==1 && u.at(0)==1) cnt=-1;
      }
    if(s.at(N-1)=='x'){
        if(u.at(N-2)==0 && u.at(N-1)==0 && u.at(0)==0) cnt=-1;
        if(u.at(N-2)==0 && u.at(N-1)==1 && u.at(0)==1) cnt=-1;
        if(u.at(N-2)==1 && u.at(N-1)==0 && u.at(0)==1) cnt=-1;
        if(u.at(N-2)==1 && u.at(N-1)==1 && u.at(0)==0) cnt=-1;
      }
    if(a[l][0]!=u.at(N-1)) cnt=-1;
    if(cnt!=-1){
      for(int j=0; j<N; j++){
        if(u.at(j)==0) t+='S';
        else t+='W';
      }
      break;
    }
  }
  if(t.size()==0) cout << -1 << endl;
  else cout << t << endl;
}