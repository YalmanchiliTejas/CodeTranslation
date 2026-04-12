#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int tan(int money,int year,double ratio,int tesuu,int ruikei){
  if(year == 0) return money+ruikei;
  return tan(money-tesuu,year-1,ratio,tesuu,(int)floor(ruikei+money*ratio));
}

int fuku(int money,int year,double ratio,int tesuu){
  if(year == 0) return money;
  return fuku((int)floor(money*ratio+money-tesuu),year-1,ratio,tesuu);
}

int main(){
  int m;
  cin >> m;
  while(m-->0){
    int money;
    cin >> money;
    int y;
    cin >> y;
    int n;
    cin >> n;

    int ans = money;
    for(int i=0;i<n;i++){
      int tf,t;
      double r;
      cin >> tf >> r >> t;
      if(tf==0)
	ans=max(ans,tan(money,y,r,t,0));
      else
	ans=max(ans,fuku(money,y,r,t));
    }
    cout << ans << endl;
  }
  return 0;
}