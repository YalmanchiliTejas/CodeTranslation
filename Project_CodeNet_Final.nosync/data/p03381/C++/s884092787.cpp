#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){

  int n,a[200000],t1,t2;
  vector <int> so;
  map <int,int>	basho;
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i],so.push_back(a[i]);
  sort(so.begin(),so.end());
  for(int i=0;i<n;i++) basho[so[i]]=i;
  t1=so[n/2-1];
  t2=so[n/2];
  for(int i=0;i<n;i++){
    if(basho[a[i]]>n/2-1) cout<<t1<<endl;
    else cout<<t2<<endl;
  }

  return 0;
}