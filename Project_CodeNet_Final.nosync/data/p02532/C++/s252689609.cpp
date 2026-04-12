#include<iostream>
#include<vector>
#include<stack>
enum{
 push,pop,move,quit
};
inline int jm(const std::string& s){
  if(s=="push")return push;
  if(s=="pop")return pop;
  if(s=="move")return move;
  if(s=="quit")return quit;
  return -1;
}
int main(){
  unsigned int n;
  std::cin>>n;
  std::vector<std::stack<char> > v(n);
  while(1){
    std::string str;
    std::cin>>str;
    switch(jm(str)){
    case push:{
      int p;
      char c;
      std::cin>>p>>c;
      v[p-1].push(c);
    }break;
    case pop:{
      int p;
      std::cin>>p;
      std::cout<<v[p-1].top()<<std::endl;
      v[p-1].pop();
    }break;
    case move:{
      int p1,p2;
      std::cin>>p1>>p2;
      v[p2-1].push(v[p1-1].top());
      v[p1-1].pop();
    }break;
    case quit:
      return 0;
    }
  }
}