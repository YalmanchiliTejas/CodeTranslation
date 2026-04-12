#include<iostream>
#include<stack>
using namespace std;

int main(){
  int n,p1,p2;
  string ans,op,c;
  stack<string> s[100];

  cin >> n;

  while(cin >> op){
    if(op=="quit")break;
    if(op=="move"){
      cin >> p1 >> p2;
      s[p2-1].push(s[p1-1].top());s[p1-1].pop();
    }
    if(op=="push"){
      cin >> p1 >> c;
      s[p1-1].push(c);
    }
    if(op=="pop"){
      cin >> p1;
      ans += s[p1-1].top();s[p1-1].pop();
    }
  }
  for(int i=0;i<(int)ans.size();i++)cout << ans[i] << endl;
}