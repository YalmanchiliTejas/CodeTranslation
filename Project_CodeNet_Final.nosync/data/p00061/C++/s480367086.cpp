#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define IREP(it,array) for(vector<int>::iterator it=array.begin(); it!=array.end(); ++it)
#define SREP(it,array) for(vector<string>::iterator it=array.begin(); it!=array.end(); ++it)
#define MP make_pair


int main()
{
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(10);

  int INF = 1000000;

  vector<pair<int,int> > list;
  int num,score;
  char del;
  while(cin>>num>>del>>score){
    if(num==0&&score==0) break;
    list.push_back( MP(score,num));
  }

  sort(list.begin(), list.end(), greater<pair<int,int> >() );


  map<int,int> sc2rank;
  int rank=1;
  for(vector<pair<int,int> >::iterator it=list.begin(); it!=list.end(); ++it){
if( sc2rank.find(it->first) == sc2rank.end() ){
sc2rank[it->first] = rank;
rank++;
}
  }

  int qu;
  while(cin >> qu){
for(vector<pair<int,int> >::iterator it=list.begin(); it!=list.end(); ++it){
if(it->second == qu){
cout << sc2rank[it->first] << endl;
break;
}
}
  }

  return 0;
}