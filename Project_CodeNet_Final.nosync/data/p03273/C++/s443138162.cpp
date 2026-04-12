#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,i,j;
  cin>>h>>w;
  vector<string> a(h);
  vector<int> r,c;
  for(i=0;i<h;i++){
    cin>>a.at(i);
    for(j=0;j<w;j++) if(a.at(i).at(j)=='#') break;
    if(j==w) r.push_back(i);
  }
  r.push_back(h);
  for(j=0;j<w;j++){
    for(i=0;i<h;i++) if(a.at(i).at(j)=='#') break;
    if(i==h) c.push_back(j);
  }
  c.push_back(w);
  for(i=0;i<h;i++){
    if(*lower_bound(r.begin(),r.end(),i)!=i){
      for(j=0;j<w;j++) if(*lower_bound(c.begin(),c.end(),j)!=j) cout<<a.at(i).at(j);
      cout<<endl;
    }
  }
}