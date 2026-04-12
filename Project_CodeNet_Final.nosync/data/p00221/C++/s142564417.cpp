#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define pb         push_back

void solve(int n,int m,bool *isok){
  vector<int> a;
  rep(i,n){
    a.pb(i);
  }
  
  int p=0;
  for(int i=1;i<m+1 && a.size() != 1;i++){
    if (isok[i]){
      p=(p+1)%a.size();
      continue;
    }
    if (!isok[i]){
      a.erase(a.begin()+p);
      if (a.size() == 0)break;
      p%=a.size();
    }
  }

  rep(i,a.size()){
    if (i)cout <<' ';
    cout <<a[i]+1;
  }
  cout << endl;
}


main(){
  int n,m;
  bool isok[10011];
  while(cin>>n>>m && n){
    rep(i,m+1)isok[i]=true;
    REP(i,1,m+1){
      string in;
      cin>>in;
      if (i%3 == 0 && i% 5 == 0){
	if (in != "FizzBuzz")isok[i]=false;
      }else if (i%3==0){
	if (in != "Fizz")isok[i]=false;
      }else if (i%5==0){
	if (in !="Buzz")isok[i]=false;
      }else {
	stringstream sin(in);
	rep(j,in.size()){
	  if (!isdigit(in[j])){
	    isok[i]=false;
	    continue;
	  }
	}
	int tmp;
	sin>>tmp;
	if (tmp != i){
	  isok[i]=false;
	}
      }
    }
    solve(n,m,isok);
  }
}