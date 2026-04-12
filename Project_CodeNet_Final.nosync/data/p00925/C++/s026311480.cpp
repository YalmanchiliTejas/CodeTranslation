#include <iostream>
#include <stack>
using namespace std;

int multi_first(string s){
  int l = (int)s.size(), ret = 0;
  stack<int> st;
  for(int i = 0; i < l; ++i){
    if(s[i] == '+') continue;
    else if(s[i] == '*'){
      int t = st.top();
      st.pop();
      st.push(t*(s[i+1]-'0'));
      ++i;
    }else{
      st.push(s[i]-'0');
    }
  }
  while(!st.empty()){
    ret += st.top();
    st.pop();
  }
  //cout << "multi_first = " << ret << endl;
  return ret;
}

int left_to_right(string s){
  int l = (int)s.size(), ret = s[0]-'0';
  for(int i = 1; i < l; ++i){
    if(s[i] == '+'){
      ret += s[i+1] - '0';
      ++i;
    }else if(s[i] == '*'){
      ret *= s[i+1] - '0';
      ++i;
    } 
  }
  //cout << "left_to_right = " << ret << endl;
  return ret;
}

int main(){
  string S;
  int N;
  cin >> S >> N;
  if(multi_first(S) == N){
    if(left_to_right(S) == N) cout << 'U' << endl;
    else cout << 'M' << endl;
  }else{
    if(left_to_right(S) == N) cout << 'L' << endl;
    else cout << 'I' << endl;
  }
  return 0;
}