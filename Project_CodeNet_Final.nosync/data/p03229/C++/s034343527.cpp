#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main(void){
  vector<int> v;
  stack<int> a;
  stack<int> b;
  vector<int> aa;
  vector<int> bb;
  int n, buf;
  long sum = 0;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> buf;
    v.push_back(buf);
  }
  sort(v.begin(),v.end());
  // for(auto a : v){
  //   cout << a << " ";
  // }
  // cout << endl;
  int del = n % 2;
  for(int i = n / 2 + del; i < n;i++) a.push(v.at(i));
  reverse(v.begin(), v.end());
  for(int i = n / 2; i < n;i++) b.push(v.at(i));

  // while(!a.empty()) {cout << a.top() << " "; a.pop();}
  // cout << endl;
  // while(!b.empty()) {cout << b.top() << " "; b.pop();}
  // cout << endl;

  aa.push_back(a.top());
  bb.push_back(a.top());
  a.pop();
  
  while(true){
    priority_queue<pair<int, string>> qu;
    if(!a.empty()){
      qu.push(make_pair(abs(aa.back() - a.top()), "aa"));
      qu.push(make_pair(abs(bb.back() - a.top()), "ba"));
    }
    if(!b.empty()){
      qu.push(make_pair(abs(aa.back() - b.top()), "ab"));
      qu.push(make_pair(abs(bb.back() - b.top()), "bb"));
    }
    if(qu.top().second == "aa"){
      aa.push_back(a.top()); a.pop();
    }else if(qu.top().second == "ab"){
      aa.push_back(b.top()); b.pop();      
    }else if(qu.top().second == "ba"){
      bb.push_back(a.top()); a.pop();      
    }else if(qu.top().second == "bb"){
      bb.push_back(b.top()); b.pop();            
    }
    if(a.empty() == true && b.empty() == true) break;
  }
  reverse(aa.begin(),aa.end());
  aa.erase(aa.end()-1);
  aa.insert(aa.end(), bb.begin(), bb.end());

  for(int i = 0; i < aa.size() - 1; i++){
    sum += abs(aa.at(i) - aa.at(i+1));
  }
  cout << sum << endl;
  return 0;
}