#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct P{
  int c,n;
  P(int c,int n):c(c),n(n){}
};
vector<P> g;
int main(void)
{
  while(1){
    int n;
    cin >> n;
    if(!n)break;
    g.clear();

    for(int i = 1; i <= n; i++){
      int b;
      cin >> b;
      if(i % 2){
	if(!g.size()){
	  g.push_back(P(b,1));
	}else if(g[g.size()-1].c == b){
	  g[g.size()-1].n++;
	}else{
	  g.push_back(P(b,1));
	}
      }else{
	if(g[g.size()-1].c == b){
	  g[g.size()-1].n++;
	}else{
	  if(g.size() >= 2){
	    g[g.size()-2].n += g[g.size()-1].n + 1;
	    g.pop_back();
	  }else{
	    g[g.size()-1].n += 1;
	    g[g.size()-1].c = b;
	  }
	}
      }  

      /*
      cout << endl;
      for(int i = 0; i < (int)g.size(); i++){
	cout << g[i].c << ":" << g[i].n << endl;
      }
      cout << endl; 
      */

    }
    int ret = 0;
    //cout << endl;
    for(int i = 0; i < (int)g.size(); i++){
      //cout << g[i].c << ":" << g[i].n << endl;
      if(!g[i].c) ret += g[i].n;
    }
    //cout << endl;
    cout << ret << endl;
  }
}