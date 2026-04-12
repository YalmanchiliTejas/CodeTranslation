#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
 string x[3], y[100][1000];
 int count[100], i, n;
 cin >> n;
 cin >> x[0];
 for(i = 0;i < 100;i++){
  count[i] = 0;
 }

 while(1){
  if(x[0] == "push") cin >> x[1] >> x[2];
  else if(x[0] == "pop") cin >> x[1];
  else if(x[0] == "move") cin >> x[1] >> x[2];
  else if(x[0] == "quit") break;
  

  if(x[0] == "push"){
    y[(int)(x[1][0] - '0')][count[(int)(x[1][0] - '0')]] = x[2];
    count[(int)(x[1][0] - '0')]++;
  }
  else if(x[0] == "pop"){
    cout << y[(int)(x[1][0] - '0')][count[(int)(x[1][0] - '0')]-1] << endl;
    count[(int)(x[1][0] - '0')]--;
  }
  else if(x[0] == "move"){
   
    y[(int)(x[2][0] - '0')][count[x[2][0] - '0']] = y[(int)(x[1][0] - '0')][count[x[1][0] - '0']-1];
    
    count[(int)(x[1][0] - '0')]--;
    count[(int)(x[2][0] - '0')]++;
  }
  cin >> x[0];
 }
 return 0; 
}