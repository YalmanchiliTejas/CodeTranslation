#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

  string t,p;
  cin>>t>>p;
  int st=t.size(),sp=p.size(),cnt=0;
  vector <int> wh;
  for(int i=0;i<st;i++){
    if(t[i]==p[cnt]){
      cnt++;
      wh.push_back(i);
    }
  }
  if(cnt!=sp){
    cout<<"no"<<endl;
    return 0;
  }
  cnt--;
  reverse(wh.begin(),wh.end());
  int tmp=0;
  for(int i=st-1;i!=-1;i--){
    if(wh.size()==tmp) break;
    if(p[cnt]==t[i]){
      if(wh[tmp]==i){
	//cout<<"where:"<<i<<endl;
	tmp++;
	cnt--;
	continue;
      }
      cout<<"no"<<endl;
      return 0;
    }
  }

  cout<<"yes"<<endl;
  
  return 0;

}