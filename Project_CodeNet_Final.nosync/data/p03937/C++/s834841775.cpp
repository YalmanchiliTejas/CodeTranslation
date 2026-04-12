#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,r=0,r_=0;
  cin>>h>>w;
  vector<string> a(h);
  for(auto& s:a){
    cin>>s;
    r+=count(s.begin(),s.end(),'#');
  }
  int x=0;
  for(int y=0;y<h;++y){
    if(a[y][x]=='#')r_++;
    else {
      cout<<"Impossible\n";
      return 0;
    }
    while(x+1<w&&a[y][x+1]=='#'){
      x++; r_++;
    }
  }
  if(r==r_)cout<<"Possible\n";
  else cout<<"Impossible\n";
  return 0;
}