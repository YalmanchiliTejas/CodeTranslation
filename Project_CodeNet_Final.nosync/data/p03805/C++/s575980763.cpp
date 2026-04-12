#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;
long fact(int n){
  if(n <= 1){
    return 1;
  }
  else{
    return n * fact(n - 1);
  }
}

vector<long*> makePath(int n){
  vector<long*> tmp;
  set<long> s;

  long ii,jj;
  long *val;
  string* str;
  vector<int>* test;
  test = new vector<int>();
  str = new string();
  long mod,v;
  for(ii=0;ii<pow(n,n);ii++){
    val = (long*)malloc(sizeof(long)*n);
    v = ii;
    s.clear();
    for(jj=0;jj<n;jj++){
      val[jj] = (v % n) + 2;
      v = v / n;
      if(s.find(val[jj]) != s.end()){
	break;
      }
      else{
	s.insert(val[jj]);
      }
    }
    if(jj == n){
      tmp.push_back(val);
    }
  }

//  for(ii=0;ii<pow(n,n);ii++){
//    for(jj=0;jj<n;jj++){
//
//    }
//  }
  return tmp;
}

int main(){
  int n,m,ii,jj;
  vector<int> path1,path2;

  vector<long*> vv;


  vv = makePath(3);
  n = 6;
  //cout << "makePath end" << endl;

  cin >> n >> m;

  vv = makePath(n-1);

//  for(ii=0;ii<fact(n-1);ii++){
//    for(jj=0;jj<n-1;jj++){
//      cout << vv[ii][jj] ;
//    }
//    cout << endl;
//  }
  
  path1.resize(m);
  path2.resize(m);

  for(ii=0;ii<m;ii++){
    cin >> path1[ii] >> path2[ii];
  }

  long graph[n+1][n+1];
  memset(graph,0,sizeof(long)*(n+1)*(n+1));
  for(ii=0;ii<m;ii++){
    graph[path1[ii]][path2[ii]] = 1;
    graph[path2[ii]][path1[ii]] = 1;
  }
//  for(ii=1;ii<=n;ii++){
//    for(jj=1;jj<=n;jj++){
//      cout << graph[ii][jj] ;
//    }
//    cout << endl;
//  }
  
//  cout << "graph make end" << endl;

  long sum = 0,from,to;
  for(ii=0;ii<fact(n-1);ii++){
    //cout << ii << endl;
    for(jj=0;jj<n-1;jj++){
      if(jj == 0){
	from = 1;
      }
      else{
	from = vv[ii][jj-1];
      }
      to = vv[ii][jj];
      if(graph[from][to] == 1 ||
	 graph[to][from] == 1){
	//cout << "ok" <<endl;
      }
      else{
	break;
      }
    }
    if(jj == (n-1)){
      sum++;
    }
  }
  cout << sum << endl;
  return 0;
}
