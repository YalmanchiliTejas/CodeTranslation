#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
typedef vector<char>::size_type vec_sz;

int main(){
  int i,n,p1,p2;
  string order;
  stack<char>block[101];
  char col;
  vector<char> ans;

  cin>>n;
  while(1){
    cin>>order;
    if(order=="quit")break;
    if(order=="push"){
      cin>>i>>col;
      block[i].push(col);
    }else if(order=="pop"){
      cin>>i;
      ans.push_back(block[i].top());
      block[i].pop();
    }else if(order=="move"){
      cin>>p1>>p2;
      col=block[p1].top();
      block[p1].pop();
      block[p2].push(col);
    }
  }
  vec_sz size =ans.size();
  for(i=0;i<size;i++){
    cout <<ans[i]<<endl;
  }
  return 0;
}

//#753546