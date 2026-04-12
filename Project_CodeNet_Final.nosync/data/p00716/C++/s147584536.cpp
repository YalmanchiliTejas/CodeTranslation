#include<iostream>

using namespace std;

int start,year,ans,test;

int fukuri(double p, int t){
  int mon = start,r;
  for(int i = 0; i < year; i++){
    r = mon*p;
    mon += r-t;
  }
  return mon;
}

int tanri(double p, int t){
  int mon = start, r = 0;
  for(int i = 0; i < year; i++){
    r+=mon*p;
    mon-=t;
  }
  return mon+r;
}

int main(){
  int num;
  cin >> num;
  while(num--){
    ans = 0;
    cin >> start >> year >> test;
    for(int i = 0; i < test; i++){
      int w,t;
      double p;
      cin >> w >> p >> t;
      if(w) ans = max(fukuri(p,t),ans);
      else ans = max(tanri(p,t),ans);
    }
    cout << ans << endl;
  }
  return 0;
}