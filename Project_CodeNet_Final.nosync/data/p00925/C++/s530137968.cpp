#include<bits/stdc++.h>
using namespace std;

string change(int a)
{
  stringstream ss;
  ss << a;
  return ss.str();
}

int main()
{
  string s;
  stack<string> st1;
  stack<string> st2;
  int res1 = 0;
  int res2 = 0;
  int ans;
  
  cin >> s;
  cin >> ans;
  
  for(int i = 0;i < s.size();i++){
    string str = &s[i];
    st1.push(str);
    if(i < 2) continue;
    
    if(s[i-1] == '+'){
      int a = atoi(st1.top().c_str());
      st1.pop();
      st1.pop();
      int b = atoi(st1.top().c_str());
      st1.pop();
      st1.push(change(a+b));
    }
    else if(s[i-1] == '*'){
      int a = atoi(st1.top().c_str());
      st1.pop();
      st1.pop();
      int b = atoi(st1.top().c_str());
      st1.pop();
      st1.push(change(a*b));
    }
    //cout << "***" << st1.top() << endl;
  }
  res1 = atoi(st1.top().c_str());
  st1.pop();
  
  for(int i = 0;i < s.size();i++){

    if(s[i] == '+') continue;

    string str = &s[i];
    st2.push(str);
    //cout << str << endl;
    if(i < 2) continue;
    
    if(s[i-1] == '*'){
      int a = atoi(st2.top().c_str());
      st2.pop();//a
      st2.pop();//*
      int b = atoi(st2.top().c_str());
      st2.pop();//b
      st2.push(change(a*b));
      //cout << "***" << st2.top() << endl;
    }
  }
  while(!st2.empty()){
    if(st2.top() == "+" || st2.top() == "*") st2.pop();
    else{
      res2 += atoi(st2.top().c_str());
      st2.pop();
      //cout << "res2 == " << res2 << endl;
      //if(!st2.empty()) cout << st2.top() << endl;
    }
  }
  //cout << res1 << endl << res2 << endl;
  
  if(res1 == ans && res2 == ans) cout << "U" << endl;
  else if(res2 == ans) cout << "M" << endl;
  else if(res1 == ans) cout << "L" << endl;
  else cout << "I" << endl;
  return 0;
}

