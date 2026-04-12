//31
#include<iostream>
#include<algorithm>
#include<utility>
#include<string>

using namespace std;

bool cmp(pair<string,int> a,pair<string,int> b){
  return a.second>b.second;
}

int main(){
  bool sec=false;
  for(int n;cin>>n,n;){
    pair<string,int> a[10];
    for(int i=0;i<n;i++){
      string s;
      int w,l,d;
      cin>>s>>w>>l>>d;
      a[i]=make_pair(s,w*3+d*1);
    }
    stable_sort(a,a+n,cmp);
    if(sec){
      cout<<endl;
    }
    sec=true;
    for(int i=0;i<n;i++){
      cout<<a[i].first<<','<<a[i].second<<endl;
    }
  }
  return 0;
}