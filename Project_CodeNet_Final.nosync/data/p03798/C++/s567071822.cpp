#include <bits/stdc++.h>
using namespace std;
     
int main() {
  long long N;
  cin >> N;
  string s;
  cin >> s;
  
  string answer = "";
  
  answer.push_back('S');
  answer.push_back('S');
  
  for(int i = 1; i < N - 1; i++){
    if(s.at(i) == 'o' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
    
    else if(s.at(i) == 'o' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
  }
  
  bool A = false;
  
  if(s.at(0) == 'o' && answer.at(N - 1) == 'S'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'S'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'W'){
      A = true;
    }
  }
  
  if(s.at(0) == 'x' && answer.at(N - 1) == 'W'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'W'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'S'){
      A = true;
    }
  }
  
  if(A == true){
    cout << answer << endl;
    return 0;
  }
  
  answer = "";
  
  answer.push_back('S');
  answer.push_back('W');
  
  for(int i = 1; i < N - 1; i++){
    if(s.at(i) == 'o' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
    
    else if(s.at(i) == 'o' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
  }
  
  A = false;
  
  if(s.at(0) == 'o' && answer.at(N - 1) == 'W'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'W'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'S'){
      A = true;
    }
  }
  
  if(s.at(0) == 'x' && answer.at(N - 1) == 'S'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'S'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'W'){
      A = true;
    }
  }
  
  if(A == true){
    cout << answer << endl;
    return 0;
  }
  
  answer = "";
  
  answer.push_back('W');
  answer.push_back('S');
  
  for(int i = 1; i < N - 1; i++){
    if(s.at(i) == 'o' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
    
    else if(s.at(i) == 'o' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
  }
  
  A = false;
  
  if(s.at(0) == 'o' && answer.at(N - 1) == 'W'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'S'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'W'){
      A = true;
    }
  }
  
  if(s.at(0) == 'x' && answer.at(N - 1) == 'S'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'W'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'S'){
      A = true;
    }
  }
  
  if(A == true){
    cout << answer << endl;
    return 0;
  }
  
  answer = "";
  
  answer.push_back('W');
  answer.push_back('W');
  
  for(int i = 1; i < N - 1; i++){
    if(s.at(i) == 'o' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
    
    else if(s.at(i) == 'o' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'S'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('W');
      }
      else{
        answer.push_back('S');
      }
    }
    
    else if(s.at(i) == 'x' && answer.at(i) == 'W'){
      if(answer.at(i - 1) == 'S'){
        answer.push_back('S');
      }
      else{
        answer.push_back('W');
      }
    }
  }
  
  A = false;
  
  if(s.at(0) == 'o' && answer.at(N - 1) == 'S'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'W'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'S'){
      A = true;
    }
  }
  
  if(s.at(0) == 'x' && answer.at(N - 1) == 'W'){
    if(s.at(N - 1) == 'o' && answer.at(N - 2) == 'S'){
      A = true;
    }
    else if(s.at(N - 1) == 'x' && answer.at(N - 2) == 'W'){
      A = true;
    }
  }
  
  if(A == true){
    cout << answer << endl;
    return 0;
  }
  
  cout << -1 << endl;
  
}