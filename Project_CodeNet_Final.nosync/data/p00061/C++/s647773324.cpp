#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
  vector<pair<int,int> > pii;
  int a,b;
  vector<int> vi;
  while(scanf("%d,%d",&a,&b),a+b){
    pii.push_back(make_pair(a,b));
    vi.push_back(b);
  }
  int ans[vi.size()+10]={};
  int anscnt=1;
  sort(vi.begin(),vi.end(),greater<int>());
  for(int i=30;i>=0;i--){
    int flag=0;
    for(int j=0;j<pii.size();j++){
      if(pii[j].second==i){
	ans[pii[j].first]=anscnt;
	flag=1;
      }
    }
    if(flag)
      anscnt++;
  }
  int n;
  while(cin>>n)
    cout<<ans[n]<<endl;
  return 0;
}