#include <iostream>
#include <stack>
using namespace std;
string str;
int N;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> str >> N;
  bool ans[2] = {false, false};
  stack<int> st;
  int i = 0;
  int product = 0;
  while(i < str.length()){
    if( isdigit(str[i]) ){
      st.push(str[i] - '0');
    }else if(str[i] == '*'){
      i++;
      int top = st.top(); st.pop();
      st.push(top*(str[i] - '0'));
    }
    i++;
  }
  while(!st.empty()){
    product += st.top();
    st.pop();
  }
  if(product == N) ans[0] = true;

  product = str[0] - '0';
  i = 2;
  while(i < str.length()){
    if( isdigit(str[i]) ){
      if(str[i-1] == '*'){
        product *= (str[i] - '0');
      }else{
        product += str[i] - '0';
      }
    }
    i++;
  }
  if(product == N){
    ans[1] = true;
  }
  if(ans[1] && ans[0]){
    cout << 'U' << endl;
  }else if(ans[0]){
    cout << 'M' << endl;
  }else if(ans[1]){
    cout << 'L' << endl;
  }else{
    cout << 'I' << endl;
  }
}