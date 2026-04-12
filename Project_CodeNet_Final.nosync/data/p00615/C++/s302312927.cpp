#include<vector>
#include<list>
#include<set>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i;
  int m,n,t;
  int mx;
  multiset<int> a;
  multiset<int>::iterator it,jt;
  while(cin>>m>>n&&m+n){
    a.clear();
    a.insert(0);
    for(i=0;i<m+n;i++){
      cin>>t;
      a.insert(t);
    }
    mx=-1;
    it=jt=a.begin();
    jt++;
    for(i=0;i<m+n;i++){
      if(mx<*jt-*it)
	mx=*jt-*it;
      it++;
      jt++;
    }
    cout<<mx<<endl;
  }
  return 0;
}