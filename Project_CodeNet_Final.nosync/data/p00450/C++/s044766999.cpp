#include <iostream>
#include <stack>
using namespace std;

int main(){
  int n,res;
  stack<pair<int,int> > stk;
  while(cin >> n,n){
    res = 0;
    for(int i = 0;i < n / 2;i++) {
      int a,b;
      cin >> a >> b;
      if(stk.empty()){
	stk.push(make_pair(b,2));
	continue;
      }
      pair<int,int> p = stk.top();stk.pop();
      if(p.first == a){
	if(a == b) stk.push(make_pair(p.first,p.second + 2));
	else {
	  if(stk.empty()) stk.push(make_pair(b,p.second + 2));
	  else{
	    pair<int,int> p2 = stk.top();stk.pop();
	    stk.push(make_pair(p2.first,p2.second + p.second + 2));
	  }
	}
      }else{
	if(a == b){
	  stk.push(p);
	  stk.push(make_pair(a,2));
	}
	else{
	  stk.push(make_pair(p.first,p.second + 2));
	}
      }
    }
    if(n % 2 == 1){
      int a;
      cin >> a;
      if(a == 0) res++;
    }
    while(!stk.empty()){
      pair<int,int> p = stk.top();stk.pop();
      if(p.first == 0) res += p.second;
    }
    cout << res << endl;
  }
  return 0;
}