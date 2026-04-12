#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int n,t,e,f=0;
  vector<int> v;
  cin>>n>>t>>e;
  for(int i=0,x;i<n;++i){cin>>x;v.push_back(x);}
  for(int i=0;i<n;++i){
    if(t%v[i]<=e||-e<=t%v[i]-v[i]){cout<<i+1<<endl;f=1;break;}
  }
  if(!f)cout<<-1<<endl;
  return 0;
}