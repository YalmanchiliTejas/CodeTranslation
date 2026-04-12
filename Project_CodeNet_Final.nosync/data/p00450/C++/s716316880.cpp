#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i=1;i<=n;i++)
struct S {bool col;int len;};
vector<S> v;

int main(){
  int n;
  bool c;
  while(cin>>n,n){
    v.clear();
    loop(i,n){
      cin>>c;
      if(i%2==1){
        if(v.empty()||v.back().col!=c){
          v.push_back((S){c,1});
        }else{
          v.back().len++;
        }
      }else{
        v.back().col=c;
        v.back().len++;
        if(v[v.size()-2].col==v.back().col){
          v[v.size()-2].len+=v.back().len;
          v.pop_back();
        }
      }
    }
    int r=0;
    for(int i=0;i<v.size();i++){
      if(v[i].col==0)r+=v[i].len;
    }
    cout<<r<<endl;
  }
  return 0;
}