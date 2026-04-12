#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
  stack<char> st[100];
  string name;
  char c,ans[100001];
  int pu,po,p1,p2,n,count=0;

  cin >> n;

  while(1){
    cin >> name;
    if(name=="push"){
      cin >> pu >> c;
      st[pu].push(c);
    }else if(name=="pop"){
      cin >> po;
      ans[count] = st[po].top();
      st[po].pop();
      count++;
    }else if(name=="move"){
      cin >> p1 >> p2;
      ans[count] = st[p1].top();
      st[p1].pop();
      st[p2].push(ans[count]);
    }else if(name=="quit"){
      break;
    }

  }

  for(int i=0;i<count;i++){
    cout << ans[i] << endl;
  }


}