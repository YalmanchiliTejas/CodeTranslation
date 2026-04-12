#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void solve(int n){
  string tm[10];
  vector< pair<int,int> > scr;    
  int a,b,c;

  scr.resize(n);
  for(int i=0;i<n;i++){
    cin>>tm[i]>>a>>b>>c;
    scr[i]=make_pair((-1)*(a*3+c),i);
  }
  sort(scr.begin(),scr.end());
  for(int i=0;i<n;i++)
    cout<<tm[scr[i].second]<<","<<(-1)*scr[i].first<<endl;
}

int main (){

  int n;
  cin>>n;
  while(n){
    solve(n);
    cin>>n;
    if(n>0) cout<<endl;
  }
  return 0;
}
  