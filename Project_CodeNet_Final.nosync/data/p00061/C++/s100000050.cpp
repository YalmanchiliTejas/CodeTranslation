#include<stdio.h>
#include<algorithm>
#include<list>
#include<vector>

using namespace std;

list<int> l[31];


int main(){
  int ord,v,i;
  while(1){
    scanf("%d,%d",&ord,&v);
    if(ord==0&&v==0) break;
    l[v].push_back(ord);
  }
  v=1;
  while(scanf("%d",&ord)!=EOF){
    for(i=30,v=1;i>-1;i--){
      list<int>::iterator it=l[i].begin();
      while(it!=l[i].end()){
	if(*it==ord){
	  printf("%d\n",v);
	  goto find;
	}
	it++;
      }
      if(!l[i].empty()) v++;
    }
  find:;
  }
  return 0;
}