#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <vector>

typedef long long ll;
using namespace std;

int main(){
  int n;
  string str;
  int i, j, k;

  cin >> n;
  cin >> str;
  int sw[n];
  int tmp;


  sw[0] = 1; sw[1] = -1;
  if(str[0]=='o'){
    tmp = -1;
  }else{
    tmp = 1;
  }
  for(i = 1; i < n-1; i++){
    if(str[i] == 'o'){
      if(sw[i] == 1){
        sw[i+1] = sw[i-1];
      }else{
        sw[i+1] = sw[i-1] * -1;
      }
    }else{
      if(sw[i] == 1){
        sw[i+1] = sw[i-1] * -1;
      }else{
        sw[i+1] = sw[i-1];
      }
    }
  }
  if(sw[n-1] == tmp && ((str[n-1] == 'o' && sw[0] * sw[n-2] * sw[n-1] == 1) || (str[n-1] == 'x' && sw[0] * sw[n-2] * sw[n-1] == -1)) ){
    for(i = 0; i < n; i++){
      if(sw[i] == 1){
        cout << 'S';
      }else{
        cout << 'W';
      }
    }
    cout << endl;
    return 0;
  }

  sw[0] = -1; sw[1] = 1;
  if(str[0]=='o'){
    tmp = -1;
  }else{
    tmp = 1;
  }
  for(i = 1; i < n-1; i++){
    if(str[i] == 'o'){
      if(sw[i] == 1){
        sw[i+1] = sw[i-1];
      }else{
        sw[i+1] = sw[i-1] * -1;
      }
    }else{
      if(sw[i] == 1){
        sw[i+1] = sw[i-1] * -1;
      }else{
        sw[i+1] = sw[i-1];
      }
    }
  }
  if(sw[n-1] == tmp && ((str[n-1] == 'o' && sw[0] * sw[n-2] * sw[n-1] == 1) || (str[n-1] == 'x' && sw[0] * sw[n-2] * sw[n-1] == -1)) ){
    for(i = 0; i < n; i++){
      if(sw[i] == 1){
        cout << 'S';
      }else{
        cout << 'W';
      }
    }
    cout << endl;
    return 0;
  }

  sw[0] = 1; sw[1] = 1;
  if(str[0]=='o'){
    tmp = 1;
  }else{
    tmp = -1;
  }
  for(i = 1; i < n-1; i++){
    if(str[i] == 'o'){
      if(sw[i] == 1){
        sw[i+1] = sw[i-1];
      }else{
        sw[i+1] = sw[i-1] * -1;
      }
    }else{
      if(sw[i] == 1){
        sw[i+1] = sw[i-1] * -1;
      }else{
        sw[i+1] = sw[i-1];
      }
    }
  }
  if(sw[n-1] == tmp && ((str[n-1] == 'o' && sw[0] * sw[n-2] * sw[n-1] == 1) || (str[n-1] == 'x' && sw[0] * sw[n-2] * sw[n-1] == -1)) ){
    for(i = 0; i < n; i++){
      if(sw[i] == 1){
        cout << 'S';
      }else{
        cout << 'W';
      }
    }
    cout << endl;
    return 0;
  }

  sw[0] = -1; sw[1] = -1;
  if(str[0]=='o'){
    tmp = 1;
  }else{
    tmp = -1;
  }
  for(i = 1; i < n-1; i++){
    if(str[i] == 'o'){
      if(sw[i] == 1){
        sw[i+1] = sw[i-1];
      }else{
        sw[i+1] = sw[i-1] * -1;
      }
    }else{
      if(sw[i] == 1){
        sw[i+1] = sw[i-1] * -1;
      }else{
        sw[i+1] = sw[i-1];
      }
    }
  }
  if(sw[n-1] == tmp && ((str[n-1] == 'o' && sw[0] * sw[n-2] * sw[n-1] == 1) || (str[n-1] == 'x' && sw[0] * sw[n-2] * sw[n-1] == -1)) ){
    for(i = 0; i < n; i++){
      if(sw[i] == 1){
        cout << 'S';
      }else{
        cout << 'W';
      }
    }
    cout << endl;
    return 0;
  }

  cout << -1 << endl;



  return 0;
}
