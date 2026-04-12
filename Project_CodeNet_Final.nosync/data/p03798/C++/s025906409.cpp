#include<bits/stdc++.h>
using namespace std;

int n;
string s;
char animal[100010];

bool search(char x,char y){
  animal[0] = x;animal[1] = y;
  for(int i = 2;i < n;i++){
    if(s.at(i-1) == 'o' && animal[i-1] == 'S'){
      animal[i] = animal[i-2];
    }
    else if(s.at(i-1) == 'o' && animal[i-1] == 'W'){
      if(animal[i-2] == 'S') animal[i] = 'W';
      if(animal[i-2] == 'W') animal[i] = 'S';
    }
    else if(s.at(i-1) == 'x' && animal[i-1] == 'S'){
      if(animal[i-2] == 'S') animal[i] = 'W';
      if(animal[i-2] == 'W') animal[i] = 'S';
    }
    else if(s.at(i-1) == 'x' && animal[i-1] == 'W'){
      animal[i] = animal[i-2];
    }
  }
  bool ok = false,ok2 = false;
  if((s.at(n-1) == 'o' && animal[n-1] == 'S') || (s.at(n-1) == 'x' && animal[n-1] == 'W')){
    if(animal[0] == animal[n-2]) ok = true;
  }
  else{
    if(animal[0] != animal[n-2]) ok = true;
  }
  if((s.at(0) == 'o' && animal[0] == 'S') || (s.at(0) == 'x' && animal[0] == 'W')){
    if(animal[1] == animal[n-1]) ok2 = true;
  }
  else{
    if(animal[1] != animal[n-1]) ok2 = true;
  }
  if(ok == true && ok2 == true){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  cin >> n;
  cin >> s;
  bool ok = false;
  for(int i = 0;i < 4;i++){
    if(i == 0) ok = search('S','S');
    if(i == 1) ok = search('S','W');
    if(i == 2) ok = search('W','S');
    if(i == 3) ok = search('W','W');
    if(ok == true){
      break;
    }
  }
  /*for(int i = 0;i < n;i++){
    cout << animal[i] << ' ' << i << endl;
  }*/
  if(ok == true){
    for(int i = 0;i < n;i++){
      cout << animal[i];
    }
    cout << endl;
  }
  else{
    cout << -1 << endl;
  }
}