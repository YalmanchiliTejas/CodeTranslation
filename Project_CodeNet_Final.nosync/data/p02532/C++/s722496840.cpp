#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main(){
  stack<string> str[111];
  string text,c,ans[1000],temp;
  int n,num,num2,cou=0,tmp=0;
  cin >> n;
  while(1){
    cin >> text;
    if(text == "quit") break;
    else if(text == "push"){
      cin >> num >> c;
      str[num].push(c);
    }
    else if(text == "pop"){
      cin >> num;
      ans[cou] = str[num].top();
      cou++;
      str[num].pop();
      tmp++;
    }
    else if(text == "move"){
      cin >> num >> num2;
      temp = str[num].top();
      str[num].pop();
      str[num2].push(temp);
    }
  }
  for(int i=0;i<tmp;i++){
    cout << ans[i] << endl;
  }
}