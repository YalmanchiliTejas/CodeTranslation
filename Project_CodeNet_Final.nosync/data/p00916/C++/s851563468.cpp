#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

struct Rectangle{
  int l,r,t,b;
  Rectangle(int _l,int _r,int _t,int _b):l(_l),r(_r),t(_t),b(_b){}
  Rectangle(){}
};

int Solve(int n){
  std::vector<Rectangle> rectangle;
  std::map<int,int> x_map,y_map;
  std::set<int> x_set,y_set;
  for(int i=0;i<n;i++){
    int l,t,r,b;
    cin>>l>>t>>r>>b;
    rectangle.push_back(Rectangle(l,r,t,b));
    x_set.insert(l);
    x_set.insert(r);
    y_set.insert(t);
    y_set.insert(b);
  }
  auto x_itr=x_set.begin();
  auto y_itr=y_set.begin();
  for(int i=0;i<x_set.size();i++){
    // cout<<*x_itr<<endl;
    x_map.insert(std::make_pair(*x_itr,i));
    x_itr++;
    // cout<<x_map[*x_itr]<<endl;
  }
  for(int i=0;i<y_set.size();i++){
    y_map.insert(std::make_pair(*y_itr,i));
    y_itr++;
  }
  for(auto &r:rectangle){
    r.l=x_map[r.l];
    r.r=x_map[r.r];
    r.b=y_map[r.b];
    r.t=y_map[r.t];
  }

  const int limit=500;

  char plane[limit][limit];
  for(int r=0;r<limit;r++){
    for(int c=0;c<limit;c++){
      plane[r][c]='.';
    }
  }

  for(auto r:rectangle){
    for(int i=r.b*2+2;i<=r.t*2+2;i++){
      plane[i][r.l*2+2]='#';
      plane[i][r.r*2+2]='#';
    }
    for(int i=r.l*2+2;i<=r.r*2+2;i++){
      plane[r.b*2+2][i]='#';
      plane[r.t*2+2][i]='#';
    }
  }

  int result=0;
  for(int row=0;row<limit;row++){
    for(int col=0;col<limit;col++){
      if(plane[row][col]=='.'){
        result++;
        typedef std::pair<int,int> pair;
        std::queue<pair> q;
        q.push(std::make_pair(row,col));
        while(!q.empty()){
          pair curr=q.front();
          q.pop();
          plane[curr.first][curr.second]='#';
          for(int vr=-1;vr<=1;vr++){
            for(int vc=-1;vc<=1;vc++){
              if((vr==0&&(vc==-1||vc==1))||(vc==0&&(vr==-1||vr==1))){
                if(curr.first+vr<0||limit<=curr.first)continue;
                if(curr.second+vc<0||limit<=curr.second+vc) continue;
                if(plane[curr.first+vr][curr.second+vc]=='.'){
                  plane[curr.first+vr][curr.second+vc]='#';
                  q.push(std::make_pair(curr.first+vr,curr.second+vc));
                }
              }
            }
          }
        }
      }
    }
  }

  return result;

}

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  while(true){
    int n;
    cin>>n;
    if(n==0) break;
    cout<<Solve(n)<<endl;
  }

  return 0;
}


