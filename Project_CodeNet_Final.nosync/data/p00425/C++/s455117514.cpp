#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

#define PI 4*atan(1);

int main(){
  int n;
  while(cin >> n && n){
    int top = 1, front = 2, right = 3, left = 4, rear = 5, under = 6;
    int sum = 1;
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      if(s == "North"){
        swap(top, rear);
        swap(top, under);
        swap(top, front);
        sum += top;
      }
      if(s == "East"){
        swap(top, right);
        swap(top, under);
        swap(top, left);
        sum += top;
      }
      if(s == "West"){
        swap(top, left);
        swap(top, under);
        swap(top, right);
        sum += top;
      }
      if(s == "South"){
        swap(top, front);
        swap(top, under);
        swap(top, rear);
        sum += top;
      }
      if(s == "Right"){
        swap(front, left);
        swap(front, rear);
        swap(front, right);
        sum += top;
      }
      if(s == "Left"){
        swap(front, right);
        swap(front, rear);
        swap(front, left);
        sum += top;
      }
    }
    cout << sum << endl;
  }
}