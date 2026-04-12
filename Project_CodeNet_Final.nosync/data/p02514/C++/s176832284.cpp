#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair< int, pair<int,int> > P;

int main(){
  int T;

  while(cin>>T,T){
    P p[T];
    for(int i=0;i<T;i++){
      cin>>p[i].first>>p[i].second.first>>p[i].second.second;
    }
    sort(p,p+T);

    for(int i=0;i<T;i++){
      printf("%04d %02d %02d\n",p[i].first,p[i].second.first,p[i].second.second);
    }
  }
}