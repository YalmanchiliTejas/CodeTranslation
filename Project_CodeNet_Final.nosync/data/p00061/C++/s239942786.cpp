#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  pair<int,int> p;
  vector<pair<int,int> > vp;
  int a,b,k=0,r[100],rh;
  char s;
  vp.clear();
  while(1){
    k++;
    cin>>a>>s>>b;
    if(a==0)break;
    p.first=b*-1;
    p.second=a;
    vp.push_back(p);
  }
  sort(vp.begin(),vp.end());
  r[vp[0].second]=1;
  rh=1;
  for(int i=1;i<k-1;i++){
    if(vp[i].first!=vp[i-1].first){
      r[vp[i].second]=++rh;
    }else r[vp[i].second]=rh;
  }
  while(cin>>a){
    cout<<r[a]<<endl;
  }
  return 0;
}