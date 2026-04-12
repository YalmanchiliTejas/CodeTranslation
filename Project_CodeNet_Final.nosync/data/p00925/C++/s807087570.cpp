#include<bits/stdc++.h>  
using namespace std;
const int INF = 999;
//世界一競技プログラミングができない人のソース2
#define int long long
int get_number(string str, int& idx){
  int ret = 0;
  while(isdigit(str[idx])){
    ret = ret * 10 + str[idx] - '0';
    ++idx;
  }
  return ret;
}

int Expression(string str, int& idx){
  int ret = get_number(str, idx);
  while(true){
    switch(str[idx]){
    case '*':
      ++idx;
      ret *= get_number( str, idx);
      break;
    default:
      return ret;
    }
  }
}

int nomal(string str, int idx = 0){
  int res = Expression(str, idx);
  while(true){
    switch(str[idx]){
    case '+':
      ++idx;
      res += Expression(str, idx);
      break;
    default:
      return res;
    }
  }
}
int special(string str, int pos = 0){
    stack < int > st;
    st.push(str[pos] - '0');
    for (int i = pos + 1; i < str.length(); i++){
        if (str[i] == '+'){
            int a = st.top(); st.pop();
            i++;
            a += (str[i] - '0');
            st.push(a);
        }
        else if (str[i] == '*'){
            int a = st.top(); st.pop();
            i++;
            a *= (str[i] - '0');
            st.push(a);
        }
    }
     
    return st.top();
}
signed main(){
  string str;
  cin >> str;
  str += "~";
  int digit;
  cin >> digit;

  bool judge_a = nomal(str) == digit;
  bool judge_b = special(str) == digit;
  if(judge_a & judge_b){
    cout << "U" << endl;
  } else if( judge_a){
    cout << "M" << endl;
  } else if( judge_b){
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }
}