#include <iostream>
#include <string>
#include <stack>
#define N_MAX 1001
using namespace std;
int main(){
  stack<char> box[N_MAX];
  int n,num,tmp;
  string odr;
  char ch;
  cin >> n;
  while(1){
    cin >> odr;
    if(odr == "push"){
      cin >> num >> ch;
      box[num].push(ch);
    }else if(odr == "pop"){
      cin >> num;
      cout << box[num].top() << endl;
      box[num].pop();
    }else if(odr == "move"){
      cin >> num;
      ch = box[num].top();
      box[num].pop();
      cin >> num;
      box[num].push(ch);
    }else break; 
  }
  return 0;
}