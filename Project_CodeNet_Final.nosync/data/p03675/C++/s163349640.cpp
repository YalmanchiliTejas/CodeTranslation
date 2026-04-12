#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  stack<int> s;
  queue<int> q;
  
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if (N % 2 == 0){
    // 偶数なら、偶数が前、奇数が後ろ
      if(i % 2 != 0){
        s.push(tmp);
      } else {
        q.push(tmp);
      }
    } else { 
      if(i % 2 == 0){
        q.push(tmp);
      } else { 
        s.push(tmp);
      }
    }
  }
  
  vector<int> v;
  while(!s.empty()){
    int x;
    x = s.top();
    s.pop();
    v.push_back(x);
  }
  while(!q.empty()){
    int x;
    x = q.front();
    q.pop();
    v.push_back(x);
  }
  if( N % 2 == 1){
    reverse(v.begin(), v.end());
  }
  
  for(int i = 0; i < v.size(); i++){
    cout << v[i];
    if( i != v.size() -1){
      cout << " " ;
    } else { 
      cout << endl;
    }
  }
}